-- 코드를 입력하세요
 SELECT MCDP_CD AS 진료과코드, COUNT(*) AS 5월예약건수
 FROM APPOINTMENT
 WHERE (MONTH(APNT_YMD) = 5) #AND (APNT_CNCL_YN='N')
 GROUP BY MCDP_CD
 ORDER BY 5월예약건수 ASC, 진료과코드 ASC;

# SELECT *
# FROM APPOINTMENT
