-- SELECT
--     F.ANIMAL_ID,
--     F.ANIMAL_TYPE,
--     F.NAME
-- FROM
--     ANIMAL_INS F
-- JOIN
--     ANIMAL_OUTS S
-- ON
--     F.ANIMAL_ID = S.ANIMAL_ID
-- WHERE
--     F.SEX_UPON_INTAKE LIKE 'Intact%'
--     AND
--     (
--         S.SEX_UPON_OUTCOME LIKE 'Spayed%'
--         OR
--         S.SEX_UPON_OUTCOME LIKE 'Neutered%'
--     )
-- ORDER BY
--     F.ANIMAL_ID ASC;

SELECT 
    F.ANIMAL_ID,
    F.ANIMAL_TYPE,
    F.NAME
FROM
    (
        SELECT 
            ANIMAL_ID, 
            ANIMAL_TYPE,
            NAME
        FROM
            ANIMAL_INS
        WHERE
            SEX_UPON_INTAKE LIKE 'Intact%'
    ) F
JOIN
    (
        SELECT
            ANIMAL_ID
        FROM
            ANIMAL_OUTS
        WHERE
            SEX_UPON_OUTCOME LIKE 'Spayed%'
            OR
            SEX_UPON_OUTCOME LIKE 'Neutered%'
    ) S
ON 
    F.ANIMAL_ID = S.ANIMAL_ID
ORDER BY
    F.ANIMAL_ID ASC;