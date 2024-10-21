-- 코드를 입력하세요
SELECT DATE_FORMAT(DATETIME, '%k') AS HOUR, COUNT(*) AS 'COUNT'
FROM ANIMAL_OUTS
WHERE DATE_FORMAT(DATETIME, '%H:%i') BETWEEN '09:00' AND '19:59'
GROUP BY DATE_FORMAT(DATETIME, '%k')
ORDER BY CAST(DATE_FORMAT(DATETIME, '%k') AS UNSIGNED) ASC;