-- -- 코드를 입력하세요
-- SELECT
--     PRICE_GROUP,
--     COUNT(*) AS COUNT
-- FROM
--     (
--         SELECT 
--             FLOOR(PRICE / 10000)*10000 AS PRICE_GROUP
--         FROM
--             PRODUCT
--     )
-- GROUP BY
--     PRICE_GROUP
-- ORDER BY
--     PRICE_GROUP ASC;

SELECT 
    TRUNC(PRICE, -4) AS PRICE_GROUP,
    COUNT(*) AS COUNT
FROM
    PRODUCT
GROUP BY
    TRUNC(PRICE, -4)
ORDER BY
    TRUNC(PRICE, -4) ASC;
