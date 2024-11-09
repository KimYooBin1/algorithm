SELECT A.ID, IF(PCT <= 0.25, 'CRITICAL',
             IF(PCT <= 0.5, 'HIGH',
               IF(PCT <= 0.75, 'MEDIUM','LOW'))) AS COLONY_NAME
FROM ECOLI_DATA A
JOIN (SELECT ID, PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) AS PCT
FROM ECOLI_DATA
) B
ON A.ID = B.ID
ORDER BY A.ID
