--Em 12.sql, escreva uma consulta SQL para listar os títulos de todos os filmes em que Johnny Depp e Helena Bonham Carter estrelaram juntos.

SELECT title FROM movies

JOIN ratings ON ratings.movie_id = movies.id
JOIN stars ON stars.movie_id = ratings.movie_id
JOIN people ON people.id = stars.person_id

WHERE people.name LIKE "Johnny Depp"

INTERSECT

SELECT title FROM movies

JOIN ratings ON ratings.movie_id = movies.id
JOIN stars ON stars.movie_id = ratings.movie_id
JOIN people ON people.id = stars.person_id

WHERE people.name LIKE "Helena Bonham Carter";
