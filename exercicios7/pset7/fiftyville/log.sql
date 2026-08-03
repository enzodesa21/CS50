-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Understand what happened on the crime scene
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = "Humphrey Street";

-- Detail from the witnesses
SELECT transcript FROM interviews
WHERE month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- Looking through the bakery security log
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM people

JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate

WHERE bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute BETWEEN 15 AND 25;

-- Looking through the ATM withdrawing transations log
SELECT people.name, atm_transactions.transaction_type FROM people

JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number

WHERE atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';

-- Find callers and receivers for phone calls under 60 seconds
SELECT phone_calls.caller, p1.name AS caller_name,
    phone_calls.receiver,p2.name AS receiver_name, phone_calls.duration FROM phone_calls

JOIN people p1 ON phone_calls.caller = p1.phone_number
JOIN people p2 ON phone_calls.receiver = p2.phone_number

WHERE phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60;

-- List of flights
SELECT f.id, f.hour, f.minute, origin.city AS origin_city, dest.city AS destination_city FROM flights AS f

JOIN airports AS origin ON f.origin_airport_id = origin.id
JOIN airports AS dest ON f.destination_airport_id = dest.id

WHERE f.month = 7
AND f.day = 29
ORDER BY f.hour ASC
LIMIT 1;

--Look for the names in the list of passangers
SELECT flights.destination_airport_id, people.name, people.phone_number, people.license_plate FROM people

JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id

WHERE flights.id = 36
ORDER BY flights.hour ASC;
