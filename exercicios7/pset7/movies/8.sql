--Em 8.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram Toy Story.

SELECT name FROM people

JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id

WHERE movies.title == "Toy Story";
