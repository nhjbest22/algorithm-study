SELECT
    ITEM_ID,
    ITEM_NAME,
    RARITY
FROM
    ITEM_INFO F
WHERE
    NOT EXISTS
        (
            SELECT
                1
            FROM
                ITEM_TREE S
            WHERE
                F.ITEM_ID = S.PARENT_ITEM_ID
        )
ORDER BY
    ITEM_ID DESC;