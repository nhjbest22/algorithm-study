-- SELECT
--     ANIMAL_ID,
--     NAME
-- FROM
--     ANIMAL_OUTS
-- WHERE
--     ANIMAL_ID NOT IN
--         (
--             SELECT 
--                 ANIMAL_ID
--             FROM
--                 ANIMAL_INS
--         )
-- ORDER BY
--     ANIMAL_ID ASC;
    
SELECT
    F.ANIMAL_ID,
    F.NAME
FROM
    ANIMAL_INS F
LEFT JOIN
    ANIMAL_OUTS S
ON
    F.ANIMAL_ID = S.ANIMAL_ID
WHERE
    S.ANIMAL_ID IS NULL
ORDER BY
    F.DATETIME ASC
FETCH FIRST 3 ROWS ONLY;