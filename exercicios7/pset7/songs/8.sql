--No 8.sql, escreva uma consulta SQL que lista os nomes das músicas que apresentam “feat” (participação) de outros artistas.
    --Músicas que apresentam outros artistas incluirão “feat.” no nome da música.

SELECT name FROM songs WHERE name LIKE "%feat.%";
