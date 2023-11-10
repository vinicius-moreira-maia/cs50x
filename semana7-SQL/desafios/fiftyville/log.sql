-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Using the informartion provided to query the reports
SELECT *
FROM
   crime_scene_reports
WHERE
   street = "Humphrey Street"
AND
   year = 2021 AND day = 28 and month = 7;

-- Reading the reports that mention bakery (Ruth, Eugene and Raymond mentions it)
SELECT
   name, transcript
FROM
   interviews
WHERE
   year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- Following Raymond's clues (checking the earliest flights in the day 29)
SELECT *
FROM
   flights
WHERE
   year = 2021 AND day = 29 AND month = 7
ORDER BY
   hour;

-- It Turns out that the earliest flight have the id = 36, so i can check all the passengers names and passport number
-- with that i can see all the personal informations of the people in that flight and compare that with other informations later
SELECT
   people.id, people.name, people.phone_number, people.passport_number, people.license_plate
FROM
   passengers
JOIN
   people
JOIN
   flights
WHERE
   flights.month = 7 AND flights.day = 29 AND flights.year = 2021
AND
   passengers.flight_id = flights.id
AND
   passengers.passport_number = people.passport_number
AND
   flights.id = 36;

-- With the infos from the last table i can check the phone calls and see which callers where in the flight 36
SELECT
   people.id, people.name, people.phone_number, phone_calls.caller, phone_calls.receiver
FROM
   phone_calls
JOIN
   people
WHERE
   phone_calls.year = 2021 AND phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.duration < 60
AND
   people.phone_number = phone_calls.caller;

-- Checking the transactions (following Eugene's clue) to get more information
SELECT
   people.name, atm_transactions.transaction_type
FROM
   people
JOIN
   atm_transactions
JOIN
   bank_accounts
WHERE
   atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND
   bank_account.account_number = atm_transactions.account_number
AND
   bank_account.person_id = people.id
AND
   atm_transactions.atm_locations = "Leggett Street";

-- The names of Bruce, Taylor and Kenny appears on the previous 3 tables (passengers of flight 36, list of callers and people who went to the ATM)

-- Checking to see the name of the receivers of the calls that they made
SELECT
   name, phone_number
FROM
   people
WHERE
   phone_number IN ("(375) 555-8161", "(066) 555-9701", "(676) 555-6554");

-- Now i know that Kenny calls to Doris, Bruce calls to Robin and Taylor calls to James

-- Checking the cameras to see if the car of someone suspect was there considering the time (10:15)
SELECT
   people.name, bakery_security_logs.hour, bakery_security_logs.minute
FROM
   people
JOIN
   bakery_security_logs
WHERE
   bakery_security_logs.year = 2021 AND bakery_security_logs.day = 28 AND bakery_security_logs.month = 7
AND
   people.license_plate = bakery_security_logs.license_plate
AND
   bakery_security_logs.hour = 10 AND bakery_security_logs.minute > 15
ORDER BY
   bakery_security_logs.minute

-- Bruce's car and Taylor's car where there, so using check50 in both callers and receivers it turns out that Bruce is the Thief and Robin is the acomplice

-- Here is the querie to see the destination of Bruce (4 appear on the flights table)
SELECT *
FROM
   airports
WHERE
   id = 4;






