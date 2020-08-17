#pragma once
#include "framework.h"

struct MYSQL_INFO
{
	CString DB_LOCATE;
	CString DB_NAME;
	CString DB_PW;
	CString DB_TABLE;
	int PORT;
};

class DBConnect
{
private:
	MYSQL m_DBcon;
	MYSQL* m_Connection;
	MYSQL_RES* m_result;
	MYSQL_ROW m_row;
	CString TableName;
public:
	DBConnect(MYSQL_INFO target, CString Table) : m_Connection(NULL)
	{
		mysql_init(&m_DBcon);
		m_Connection = mysql_real_connect(&m_DBcon,
			(LPSTR)(LPCTSTR)target.DB_LOCATE,
			(LPSTR)(LPCTSTR)target.DB_NAME,
			(LPSTR)(LPCTSTR)target.DB_PW,
			(LPSTR)(LPCTSTR)target.DB_TABLE,
			target.PORT,
			NULL, 0);
		mysql_query(&m_DBcon, "set names euckr");

		TableName.Format(_T("%s.%s"), target.DB_TABLE, Table); // DataBase.TableName → memberdb.member
		if (!isSafeConnect())
		{
			AfxMessageBox(_T("안정적인 연결이 아닙니다."));
		}
	}
	~DBConnect()
	{
		mysql_close(m_Connection);
	}
	
	BOOL isSafeConnect(void)
	{
		CString form;
		form.Format(_T("This Connect is Failed : %s"), mysql_error(&m_DBcon));
		if (m_Connection == NULL)
		{
			AfxMessageBox(form, MB_OK | MB_ICONERROR);
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}

	void InsertData(CString ID, CString PW, CString NAME, CString BIRTH, CString PHONE, CString ADDRESS, CString GENDER, CString EMAIL)
	{	
		if (ID == _T("") || PW == _T("") || NAME == _T("") || PHONE == _T(""))
		{
			AfxMessageBox(_T("누락된 정보가 있습니다. 입력해주시길 바랍니다."));
			return;
		}
		CString Query;
		Query.Format(_T("INSERT INTO %s VALUES('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%d', '%d');"), 
			TableName, ID, PW, NAME, BIRTH, PHONE, ADDRESS, GENDER, EMAIL, 1, 0);
		mysql_query(m_Connection, (LPSTR)(LPCTSTR)Query);
		mysql_query(m_Connection, "commit;");
	}

	BOOL CanUseID(CString JoinID) // 아이디 중복검사 함수
	{
		CString Query;
		Query.Format(_T("select count(*) from %s where ID = '%s';"), TableName, JoinID);
		mysql_query(m_Connection, (LPSTR)(LPCTSTR)Query);
		if ((m_result = mysql_store_result(m_Connection)) == NULL) { return FALSE; }
		m_row = mysql_fetch_row(m_result);
		
		CString SCount;
		SCount.Format(_T("%s"), m_row[0]);
		int count = _ttoi(SCount);

		if (count == 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	BOOL CorrectID(CString ID, CString PW) // 계정 확인 함수, 로그인
	{
		CString Query;
		Query.Format(_T("select * from %s;"), TableName);
		mysql_query(m_Connection, (LPSTR)(LPCTSTR)Query);
		m_result = mysql_store_result(m_Connection);
		int field = mysql_num_fields(m_result); // columm 갯수
		
		while (m_row = mysql_fetch_row(m_result)) // 반복 호출시 그 다음 행으로 넘어감
		{
			if ((ID == m_row[0]) && (PW == m_row[1]))
			{
				return TRUE;
			}
		}
		return FALSE;
	}

	CString WhatName(CString UserID)
	{
		CString Query;
		CString SearchID;
		Query.Format(_T("select* from %s where ID ='%s';"), TableName, UserID);
		mysql_query(m_Connection, (LPSTR)(LPCTSTR)Query);
		m_result = mysql_store_result(m_Connection);

		while (m_row = mysql_fetch_row(m_result))
		{
			if (UserID == m_row[0])
			{
				SearchID = m_row[2];
				return SearchID;
			}
		}
		AfxMessageBox(_T("이름을 찾지 못하였습니다."));
		return _T("end");
	}

	CString WhatLevel(CString UserID)
	{
		CString Query;
		CString Level;
		Query.Format(_T("select* from %s where ID ='%s';"), TableName, UserID);
		mysql_query(m_Connection, (LPSTR)(LPCTSTR)Query);
		m_result = mysql_store_result(m_Connection);

		while (m_row = mysql_fetch_row(m_result))
		{
			if (UserID == m_row[0])
			{
				Level = m_row[8];
				return Level;
			}
		}
		AfxMessageBox(_T("LEVEL 찾지 못하였습니다."));
		return _T("end");
	}

	CString WhatPoint(CString UserID)
	{
		CString Query;
		CString Point;
		Query.Format(_T("select* from %s where ID ='%s';"), TableName, UserID);
		mysql_query(m_Connection, (LPSTR)(LPCTSTR)Query);
		m_result = mysql_store_result(m_Connection);

		while (m_row = mysql_fetch_row(m_result))
		{
			if (UserID == m_row[0])
			{
				Point = m_row[9];
				return Point;
			}
		}
		AfxMessageBox(_T("POINT 찾지 못하였습니다."));
		return _T("end");
	}
};