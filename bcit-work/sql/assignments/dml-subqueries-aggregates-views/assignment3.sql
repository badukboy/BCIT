SET ECHO ON
SPOOL C:\Users\Kevin\Desktop\DatabaseAssignment3\Asn3_LoconteD_CsapkoK.txt

-- COMP 2714
-- SET 2E
-- Assignment Asn03
-- Csapko, Kevin A00800403
-- Loconte, Daniel A00826877
-- email: kcsapko@gmail.com
-- email: dloconte@live.ca

ALTER SESSION SET NLS_DATE_FORMAT='YYYY-MM-DD';

DROP TABLE Booking;
DROP TABLE Guest;
DROP TABLE Room;
DROP TABLE Hotel;

-- Create Sample Tables
CREATE TABLE Hotel
(hotelNo         NUMBER(4)       NOT NULL
,hotelName       VARCHAR2(16)    NOT NULL
,hotelAddress    VARCHAR2(40)    NOT NULL
,PRIMARY KEY (hotelNo)
);

CREATE TABLE Room
(hotelNo         NUMBER(4)       NOT NULL
,roomNo          NUMBER(4)       NOT NULL
,type            VARCHAR2(8)     NOT NULL
,price           NUMBER(6,2)     NOT NULL
,PRIMARY KEY (hotelNo, roomNo)
);

CREATE TABLE Guest
(guestNo         NUMBER(4)       NOT NULL
,guestName       VARCHAR2(15)    NOT NULL
,guestAddress    VARCHAR2(40)    NOT NULL
,PRIMARY KEY (guestNo)
);

CREATE TABLE Booking
(hotelNo          NUMBER(4)      NOT NULL
,guestNo          NUMBER(4)      NOT NULL
,dateFrom         DATE           NOT NULL
,dateTo           DATE
,roomNo           NUMBER(4)      NOT NULL
,PRIMARY KEY (hotelNo, guestNo, dateFrom)
);

-- Insert Sample Data
INSERT INTO Hotel
  VALUES (1, 'Grosvenor Hotel', '100 Oxford Road, London');
INSERT INTO Hotel
  VALUES (2, 'Meridian Hotel', '789 Howe Street, Vancouver');
INSERT INTO Hotel
  VALUES (3, 'Holiday Inn', '56 Edinburg Square, London');
INSERT INTO Hotel
  VALUES (4, 'The Ramada', '22 Memorial Avenue, New York');
INSERT INTO Hotel
  VALUES (5, 'Imperial Palace', '777 Lonsdale, North Vancouver');
INSERT INTO Hotel
  VALUES (6, 'Park Royal Hotel', '88 JANine Drive, West Vancouver');
INSERT INTO Hotel
  VALUES (7, 'Delta Inn', '900 Burrard Street, Vancouver');
INSERT INTO Hotel
  VALUES (8, 'Sheraton Hotel', '123 Granville Street, Vancouver');
INSERT INTO Hotel
  VALUES (9, 'Royale London', '500 Cambridge Road, London');
INSERT INTO Hotel
  VALUES (10, 'Olympic Resort', '223 Olympic Street, Whistler');

INSERT INTO Room
  VALUES (1, 1, 'Single', 40);
INSERT INTO Room
  VALUES (1, 2, 'Single', 40);
INSERT INTO Room
  VALUES (1, 3, 'Single', 40);
INSERT INTO Room
  VALUES (1, 4, 'Single', 40);
INSERT INTO Room
  VALUES (1, 5, 'Double', 55);
INSERT INTO Room
  VALUES (1, 6, 'Double', 55);
INSERT INTO Room
  VALUES (1, 7, 'Double', 55);
INSERT INTO Room
  VALUES (1, 8, 'Double', 55);
INSERT INTO Room
  VALUES (1, 9, 'Family', 85);
INSERT INTO Room
  VALUES (1, 10, 'Family', 90);
INSERT INTO Room
  VALUES (1, 11, 'Deluxe', 110);
INSERT INTO Room
  VALUES (1, 12, 'Deluxe', 120);
INSERT INTO Room
  VALUES (1, 13, 'Deluxe', 120);
INSERT INTO Room
  VALUES (2, 1, 'Double', 80);
INSERT INTO Room
  VALUES (2, 2, 'Double', 80);
INSERT INTO Room
  VALUES (2, 3, 'Double', 80);
INSERT INTO Room
  VALUES (2, 4, 'Double', 80);
INSERT INTO Room
  VALUES (2, 5, 'Double', 80);
INSERT INTO Room
  VALUES (2, 6, 'Family', 90);
INSERT INTO Room
  VALUES (2, 7, 'Family', 90);
INSERT INTO Room
  VALUES (2, 8, 'Family', 90);
INSERT INTO Room
  VALUES (2, 9, 'Family', 90);
INSERT INTO Room
  VALUES (2, 10, 'Deluxe', 150);
INSERT INTO Room
  VALUES (2, 11, 'Deluxe', 150);
INSERT INTO Room
  VALUES (2, 12, 'Deluxe', 150);
INSERT INTO Room
  VALUES (3, 1, 'Single', 35);
INSERT INTO Room
  VALUES (3, 2, 'Single', 35);
INSERT INTO Room
  VALUES (3, 3, 'Single', 35);
INSERT INTO Room
  VALUES (3, 4, 'Single', 35);
INSERT INTO Room
  VALUES (3, 5, 'Single', 35);
INSERT INTO Room
  VALUES (3, 6, 'Single', 35);
INSERT INTO Room
  VALUES (3, 7, 'Single', 35);
INSERT INTO Room
  VALUES (3, 8, 'Single', 35);
INSERT INTO Room
  VALUES (3, 9, 'Double', 50);
INSERT INTO Room
  VALUES (3, 10, 'Double', 50);
INSERT INTO Room
  VALUES (3, 11, 'Double', 50);
INSERT INTO Room
  VALUES (3, 12, 'Double', 50);
INSERT INTO Room
  VALUES (3, 13, 'Double', 50);
INSERT INTO Room
  VALUES (3, 14, 'Double', 50);
INSERT INTO Room
  VALUES (4, 1, 'Double', 100);
INSERT INTO Room
  VALUES (4, 2, 'Double', 100);
INSERT INTO Room
  VALUES (4, 3, 'Double', 100);
INSERT INTO Room
  VALUES (4, 4, 'Double', 100);
INSERT INTO Room
  VALUES (4, 5, 'Double', 100);
INSERT INTO Room
  VALUES (4, 6, 'Double', 100);
INSERT INTO Room
  VALUES (4, 7, 'Family', 160);
INSERT INTO Room
  VALUES (4, 8, 'Family', 160);
INSERT INTO Room
  VALUES (4, 9, 'Family', 160);
INSERT INTO Room
  VALUES (4, 10, 'Family', 160);
INSERT INTO Room
  VALUES (4, 11, 'Family', 160);
INSERT INTO Room
  VALUES (4, 12, 'Deluxe', 240);
INSERT INTO Room
  VALUES (4, 13, 'Deluxe', 240);
INSERT INTO Room
  VALUES (4, 14, 'Deluxe', 240);
INSERT INTO Room
  VALUES (4, 15, 'Deluxe', 240);
INSERT INTO Room
  VALUES (4, 16, 'Deluxe', 240);
INSERT INTO Room
  VALUES (5, 1, 'Double', 80);
INSERT INTO Room
  VALUES (5, 2, 'Double', 80);
INSERT INTO Room
  VALUES (5, 3, 'Double', 80);
INSERT INTO Room
  VALUES (5, 4, 'Double', 80);
INSERT INTO Room
  VALUES (5, 5, 'Double', 80);
INSERT INTO Room
  VALUES (5, 6, 'Double', 80);
INSERT INTO Room
  VALUES (5, 7, 'Family', 120);
INSERT INTO Room
  VALUES (5, 8, 'Family', 120);
INSERT INTO Room
  VALUES (5, 9, 'Family', 120);
INSERT INTO Room
  VALUES (5, 10, 'Family', 120);
INSERT INTO Room
  VALUES (5, 11, 'Family', 120);
INSERT INTO Room
  VALUES (5, 12, 'Family', 120);
INSERT INTO Room
  VALUES (5, 13, 'Deluxe', 145);
INSERT INTO Room
  VALUES (5, 14, 'Deluxe', 145);
INSERT INTO Room
  VALUES (5, 15, 'Deluxe', 145);
INSERT INTO Room
  VALUES (5, 16, 'Deluxe', 145);
INSERT INTO Room
  VALUES (5, 17, 'Deluxe', 145);
INSERT INTO Room
  VALUES (5, 18, 'Deluxe', 145);
INSERT INTO Room
  VALUES (6, 1, 'Single', 48);
INSERT INTO Room
  VALUES (6, 2, 'Single', 48);
INSERT INTO Room
  VALUES (6, 3, 'Single', 48);
INSERT INTO Room
  VALUES (6, 4, 'Single', 48);
INSERT INTO Room
  VALUES (6, 5, 'Single', 48);
INSERT INTO Room
  VALUES (6, 6, 'Single', 48);
INSERT INTO Room
  VALUES (6, 7, 'Single', 48);
INSERT INTO Room
  VALUES (6, 8, 'Single', 48);
INSERT INTO Room
  VALUES (6, 9, 'Double', 86);
INSERT INTO Room
  VALUES (6, 10, 'Double', 86);
INSERT INTO Room
  VALUES (6, 11, 'Double', 86);
INSERT INTO Room
  VALUES (6, 12, 'Double', 86);
INSERT INTO Room
  VALUES (6, 13, 'Double', 86);
INSERT INTO Room
  VALUES (6, 14, 'Double', 86);
INSERT INTO Room
  VALUES (6, 15, 'Double', 86);
INSERT INTO Room
  VALUES (6, 16, 'Double', 86);
INSERT INTO Room
  VALUES (7, 1, 'Double', 75);
INSERT INTO Room
  VALUES (7, 2, 'Double', 75);
INSERT INTO Room
  VALUES (7, 3, 'Double', 75);
INSERT INTO Room
  VALUES (7, 4, 'Double', 75);
INSERT INTO Room
  VALUES (7, 5, 'Double', 75);
INSERT INTO Room
  VALUES (7, 6, 'Double', 75);
INSERT INTO Room
  VALUES (7, 7, 'Double', 75);
INSERT INTO Room
  VALUES (7, 8, 'Double', 75);
INSERT INTO Room
  VALUES (7, 9, 'Double', 75);
INSERT INTO Room
  VALUES (7, 10, 'Double', 75);
INSERT INTO Room
  VALUES (7, 11, 'Double', 75);
INSERT INTO Room
  VALUES (7, 12, 'Double', 75);
INSERT INTO Room
  VALUES (8, 1, 'Double', 95);
INSERT INTO Room
  VALUES (8, 2, 'Double', 95);
INSERT INTO Room
  VALUES (8, 3, 'Double', 95);
INSERT INTO Room
  VALUES (8, 4, 'Double', 95);
INSERT INTO Room
  VALUES (8, 5, 'Double', 95);
INSERT INTO Room
  VALUES (8, 6, 'Family', 125);
INSERT INTO Room
  VALUES (8, 7, 'Family', 125);
INSERT INTO Room
  VALUES (8, 8, 'Family', 125);
INSERT INTO Room
  VALUES (8, 9, 'Family', 125);
INSERT INTO Room
  VALUES (8, 10, 'Family', 125);
INSERT INTO Room
  VALUES (8, 11, 'Deluxe', 155);
INSERT INTO Room
  VALUES (8, 12, 'Deluxe', 155);
INSERT INTO Room
  VALUES (8, 13, 'Deluxe', 155);
INSERT INTO Room
  VALUES (8, 14, 'Deluxe', 155);
INSERT INTO Room
  VALUES (8, 15, 'Deluxe', 155);
INSERT INTO Room
  VALUES (8, 16, 'Single', 45);
INSERT INTO Room
  VALUES (8, 17, 'Single', 45);
INSERT INTO Room
  VALUES (8, 18, 'Single', 45);
INSERT INTO Room
  VALUES (8, 19, 'Single', 45);
INSERT INTO Room
  VALUES (8, 20, 'Single', 45);

INSERT INTO Guest
  VALUES (1, 'Tony Saunders', '2000 Queens Avenue, Winnipeg');
INSERT INTO Guest
  VALUES (2, 'Ed Cunningham', '30 Oak Street, Vancouver');
INSERT INTO Guest
  VALUES (3, 'Dawn Smith', '25 Walton Drive, Banff');
INSERT INTO Guest
  VALUES (4, 'George Michaels', '30 Hampton Street, London');
INSERT INTO Guest
  VALUES (5, 'Rick Hamilton', '987 King Edward Road, London');
INSERT INTO Guest
  VALUES (6, 'Floyd Mann', '8 Wascana Crescent, Regina');
INSERT INTO Guest
  VALUES (7, 'Thomas Lee', '200 Main Street, Vancouver');
INSERT INTO Guest
  VALUES (8, 'Sandy Alford', '234 Ontario Street, Montreal');
INSERT INTO Guest
  VALUES (9, 'Peter Kennedy', '20 Austin Drive, London');
INSERT INTO Guest
  VALUES (10, 'Gordon Ho', '5 No. 3 Road, Richmond');
INSERT INTO Guest
  VALUES (11, 'Diana Darby', '50 Robson Street, Vancouver');
INSERT INTO Guest
  VALUES (12, 'Sundeep Mohan', '1000 Victoria Avenue, London');
INSERT INTO Guest
  VALUES (13, 'Eileen Reynolds', '100 Willow Stree, Calgary');
INSERT INTO Guest
  VALUES (14, 'Ken Matsuda', '333 100th Avenue, Vancouver');
INSERT INTO Guest
  VALUES (15, 'Ivan Pratt', '20 Lincoln Square, London');

INSERT INTO Booking
  VALUES (1, 5, '2012-01-16', '2012-01-18', 7);
INSERT INTO Booking
  VALUES (1, 9, '2012-01-27', '2012-02-04', 5);
INSERT INTO Booking
  VALUES (1, 9, '2012-02-07', '2012-02-14', 5);
INSERT INTO Booking
  VALUES (1, 9, '2012-03-07', '2012-03-14', 5);
INSERT INTO Booking
  VALUES (1, 10, '2012-03-22', '2012-03-31', 1);
INSERT INTO Booking
  VALUES (1, 11, '2012-02-06', '2012-02-22', 3);
INSERT INTO Booking
  VALUES (1, 12, '2012-01-21', '2012-02-24', 4);
INSERT INTO Booking
  VALUES (1, 13, '2012-01-31', NULL, 7);
INSERT INTO Booking
  VALUES (1, 14, '2012-01-25', '2012-01-28', 2);
INSERT INTO Booking
  VALUES (1, 15, '2012-01-22', '2012-02-02', 3);
INSERT INTO Booking
  VALUES (2, 1, '2012-01-21', '2012-01-23', 9);
INSERT INTO Booking
  VALUES (2, 6, '2012-01-21', NULL, 10);
INSERT INTO Booking
  VALUES (3, 2, '2012-01-26', NULL, 3);
INSERT INTO Booking
  VALUES (3, 6, '2012-03-05', '2012-03-07', 12);
INSERT INTO Booking
  VALUES (4, 11, '2012-01-27', '2012-01-28', 14);
INSERT INTO Booking
  VALUES (4, 7, '2012-02-09', '2012-02-11', 4);
INSERT INTO Booking
  VALUES (4, 8, '2012-03-10', '2012-03-18', 7);
INSERT INTO Booking
  VALUES (5, 3, '2012-02-06', '2012-02-08', 17);
INSERT INTO Booking
  VALUES (5, 11, '2012-02-06', NULL, 16);
INSERT INTO Booking
  VALUES (6, 1, '2012-01-31', '2012-02-02', 5);
INSERT INTO Booking
  VALUES (6, 14, '2012-03-06', '2012-03-08', 8);
INSERT INTO Booking
  VALUES (6, 9, '2012-03-06', NULL, 4);
INSERT INTO Booking
  VALUES (7, 15, '2012-02-28', '2102-03-05', 1);
INSERT INTO Booking
  VALUES (7, 4, '2012-02-02', '2102-02-04', 2);
INSERT INTO Booking
  VALUES (8, 1, '2012-02-03', '2012-03-26', 15);
INSERT INTO Booking
  VALUES (8, 12, '2012-02-01', '2012-03-07', 20);
INSERT INTO Booking
  VALUES (8, 5, '2012-01-19', '2012-02-28', 1);

COMMIT;

-- Q1) What is the average price of a room in London? A) Do this using JOIN, B)
-- Do this using subquery.

-- Q1, Part A)
SELECT h.hotelAddress, h.hotelNo, r.hotelNo, AVG(r.price) AS avgPrice
  FROM Hotel h
    INNER JOIN Room r
     ON r.hotelNo = h.hotelNo
  WHERE hotelAddress LIKE '%, London'
  GROUP BY h.hotelAddress,
           h.hotelNo,
		   r.hotelNo
  ORDER BY r.hotelNo;

-- Q1, Part B)
SELECT r.hotelNo, AVG(r.price)
  FROM Room r
    WHERE r.hotelNo IN
  (SELECT h.hotelNo
    FROM Hotel h
      WHERE hotelAddress LIKE '% London')
  GROUP BY r.hotelNo;

-- Q2) Use the month of 2012-02 instead of August, and do the query for each 
-- hotel: i.e. How many different guests have made bookings for 2012-02 for each 
-- hotel?
			
SELECT DISTINCT hotelNo, guestNo
  FROM Booking b
    WHERE hotelNo
	  IN (SELECT DISTINCT hotelNo
	    FROM Hotel
      WHERE dateFrom <= DATE '2012-02-29' 
	  AND (dateTo IS NULL 
	  OR dateTo >= DATE '2012-02-01'));
			
-- Q3) List the details of all rooms at the Grosvenor Hotel, including the name 
-- of the guest staying in the room, if the room is occupied? Use 2012-02-01 as 
-- today's date. List them in roomNo order.

SELECT DISTINCT r.*, info.guestName
  FROM Room r 
    LEFT JOIN 
	(SELECT b.roomNo, g.guestName, g.guestNo
		FROM Guest g
		  INNER JOIN Booking b
		    ON b.guestNo = g.guestNo
			  WHERE hotelNo = '1'
			    AND b.dateFrom <= DATE '2012-02-01' 
			    AND (b.dateTo IS NULL 
				 OR b.dateTo >= DATE '2012-02-01')) info
		ON info.roomNo = r.roomNo
		WHERE hotelNo = '1'
		ORDER BY r.roomNo ASC;
  
-- Q4) List the rooms that are currently unoccupied at the Grosvenor Hotel? Use
-- 2012-02-01 as today's date. Use NOT IN to solve this query. List in roomNo
-- order.

SELECT roomNo
  FROM Room
    WHERE hotelNo = '1'
	AND roomNo NOT IN
	  (SELECT roomNo FROM Booking
	    WHERE hotelNo = '1'
		  AND dateFrom <= DATE '2012-02-01' 
			    AND (dateTo IS NULL 
				 OR dateTo >= DATE '2012-02-01'))
	ORDER BY roomNo ASC;
  
-- Q5) Use 2012-02-01 as today's date. Use NOT EXISTS to solve this query. List
-- in roomNo order.

SELECT roomNo
  FROM Room
 WHERE 
   NOT EXISTS (SELECT guestNo
		        FROM Booking
				WHERE Booking.roomNo = Room.roomNo
		         AND hotelNo = '1'
		         AND dateFrom <= DATE '2012-02-01' 
			     AND (dateTo IS NULL 
		          OR dateTo >= DATE '2012-02-01'))
    AND hotelNo = '1'				  
  ORDER BY roomNo ASC;
  
-- Q6) Use 2012-02-01 as today's date. Use LEFT JOIN to solve this query. List 
-- in roomNo order.

SELECT r.roomNo
  FROM Room r 
    LEFT JOIN (SELECT b.roomNo, g.guestNo, g.guestName
		    FROM Guest g
				INNER JOIN Booking b
				ON b.guestNo = g.guestNo
		        WHERE b.hotelNo = '1'
				AND dateFrom <= DATE '2012-02-01' 
			    AND (dateTo IS NULL 
				OR dateTo >= DATE '2012-02-01')) Info
			ON r.roomNo = Info.roomNo
            WHERE r.hotelNo = '1'
			AND Info.guestName IS NULL
  ORDER BY roomNo ASC;

-- Q7) Use 2012-02-01 as today's date. Use MINUS to solve this query. List in 
-- roomNo order.

SELECT roomNo
  FROM Room
    WHERE hotelNo = '1'
MINUS
SELECT roomNo FROM Room
  NATURAL JOIN Booking b
    WHERE dateFrom <= DATE '2012-02-01' 
      AND (dateTo IS NULL 
	   OR dateTo >= DATE '2012-02-01')
	  AND hotelNo = '1';

-- Q8)  What is the average number of bookings for each hotel Use the month of
-- 2012-02 instead of August.

SELECT AVG(Average_Bookings) FROM
  (SELECT COUNT (*) AS Average_Bookings
    FROM Hotel
    NATURAL JOIN Booking
      WHERE dateFrom <= DATE '2012-02-01' 
	    AND (dateTo IS NULL 
		  OR dateTo >= DATE '2012-02-01')
		  GROUP BY hotelNo);

-- Q9) What is the lost income from unoccupied rooms at each hotel on February
-- 1st 2012? Use 2012-02-01 as today's date. List hotelNo, hotelName and
-- LostIncome, in hotelNo order.

SELECT hotelNo, SUM(price) AS LOSTINCOME
  FROM (SELECT roomNo, price, hotelNo
	   FROM Room
	   MINUS
	   SELECT roomNo, price, hotelNo 
	   FROM Room NATURAL JOIN Booking
	   WHERE dateFrom <= DATE '2012-02-01' 
	   AND (dateTo IS NULL 
	   OR dateTo >= DATE '2012-02-01'))
  NATURAL JOIN Hotel
  GROUP BY hotelNo
  ORDER BY hotelNo ASC;
  
-- Q10) Create a view containing the account for each at the Grosvenor Hotel
-- Use 2012-02-01 as today, and guestAccount as view name. [The account 
-- info for each guest means: Room (roomNo), Name (guestName), Check-in 
-- (dateFrom), Check-out (dateTo), Rate (room price), #Days (calculate from 
-- dateTo and dateFrom), and Total (calculate from dateTo, dateFrom and price).
-- ] Add a query to test the view.

DROP VIEW GROSVENORDETAILS;
CREATE VIEW GROSVENORDETAILS AS (
  SELECT roomNo AS Room, guestName AS Name, dateFrom AS CheckIn,
         dateTo AS CheckOut, price AS Rate,
		 (dateTo - dateFrom) AS NumOfDays, 
		 CAST(dateTo - dateFrom AS NUMERIC) * price AS Total
	FROM Booking NATURAL JOIN Guest NATURAL JOIN Room
   WHERE hotelNo = 1);
	
SELECT * FROM GROSVENORDETAILS;
	
SPOOL OFF