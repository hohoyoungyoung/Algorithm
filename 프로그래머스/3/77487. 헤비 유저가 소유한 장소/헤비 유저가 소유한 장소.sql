-- 코드를 입력하세요
SELECT A.ID, A.NAME, A.HOST_ID
FROM PLACES A
WHERE A.HOST_ID IN (
                    SELECT B.HOST_ID
                    FROM PLACES B
                    GROUP BY B.HOST_ID
                    HAVING COUNT(B.HOST_ID) >= 2)
ORDER BY A.ID ASC;