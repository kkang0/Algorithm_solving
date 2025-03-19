-- 코드를 작성해주세요
SELECT SUM(SCORE) AS SCORE, C.EMP_NO, EMP_NAME, POSITION, EMAIL
FROM HR_DEPARTMENT AS A JOIN HR_EMPLOYEES AS B
ON A.DEPT_ID = B.DEPT_ID JOIN HR_GRADE AS C
ON B.EMP_NO = C.EMP_NO
GROUP BY B.EMP_NO
ORDER BY SCORE DESC
LIMIT 1;