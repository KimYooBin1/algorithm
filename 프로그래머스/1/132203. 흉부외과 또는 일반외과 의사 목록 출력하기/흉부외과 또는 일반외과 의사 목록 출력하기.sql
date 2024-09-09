-- 코드를 입력하세요
SELECT DR_NAME, DR_ID, MCDP_CD, SUBSTRING(HIRE_YMD,1,10) from DOCTOR where MCDP_CD in ("GS", "CS") order by HIRE_YMD desc, DR_NAME asc