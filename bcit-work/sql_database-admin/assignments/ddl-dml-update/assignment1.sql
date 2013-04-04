SET ECHO ON
SPOOL C:\Users\Kevin\Desktop\DatabaseAssignment1\Asn_LoconteD_CsapkoK.txt

--  COMP 2714 
--  SET 2E
--  Assignment Asn01
--  Csapko, Kevin A00800403
--  Loconte, Daniel A00826877
--  email: kcsapko@gmail.com
--  email: dloconte@live.ca

ALTER SESSION SET NLS_DATE_FORMAT='YYYY-MM-DD';
SELECT SYSDATE
FROM DUAL;

-- Q1: Dropping tables first before creating
DROP TABLE OldBooking;
DROP TABLE Booking;
DROP TABLE Room;
DROP TABLE Guest;
DROP TABLE Hotel;

-- Q2: Creating Hotel table
CREATE TABLE Hotel
(hotelNo		CHAR(9)			NOT NULL
,hotelName		VARCHAR(30)		NOT NULL
,city			VARCHAR(30)		NOT NULL
,CONSTRAINT PKhotelNo PRIMARY KEY (hotelNo)
);

-- Q2: Creating Room table
CREATE TABLE Room
(roomNo		VARCHAR(3)		NOT NULL
,hotelNo	CHAR(9)			NOT NULL
,type		VARCHAR(6)		NOT NULL
,price		DECIMAL(5,2)	NOT NULL
,CONSTRAINT PKRoom PRIMARY KEY (roomNo, hotelNo)
,CONSTRAINT FKhotelNo FOREIGN KEY (hotelNo) REFERENCES Hotel (hotelNo)
,CONSTRAINT chk_room_type CHECK(type IN('Single', 'Double', 'Family'))
,CONSTRAINT chk_price CHECK(price BETWEEN 10 AND 100)
,CONSTRAINT chk_room_num CHECK(roomNo BETWEEN 1 AND 100)
);

-- Q3: Creating Guest table
CREATE TABLE Guest
(guestNo		CHAR(9)			NOT NULL
,guestName		VARCHAR(30)		NOT NULL
,guestAddress	VARCHAR(50)		NOT NULL
,CONSTRAINT PKguestNo PRIMARY KEY (guestNo)
);

-- Q3: Creating Booking table
CREATE TABLE Booking
(hotelNo	CHAR (9)		NOT NULL
,guestNo	CHAR (9)		NOT NULL
,dateFrom	DATE			NOT NULL
,dateTo		DATE			NOT NULL
,roomNo		VARCHAR (3)	    NOT NULL
,CONSTRAINT PKBooking PRIMARY KEY (hotelNo, guestNo, dateFrom)
);

-- Q4: Inserting sample data for Hotel table
INSERT INTO Hotel
	VALUES('HC5678578', 'Hotel California', 'Burbank');
	
INSERT INTO Hotel
	VALUES('HM2927848', 'Hampton', 'Newport');
	
INSERT INTO Hotel
	VALUES('FS3938237', 'Five Seasons', 'Carolina');

-- Q4: Inserting sample data for Room table
INSERT INTO Room
	VALUES('54', 'FS3938237', 'Single', '50');
	
INSERT INTO Room
	VALUES('89', 'HM2927848', 'Family', '80');

INSERT INTO Room
	VALUES('100', 'HC5678578', 'Double', '75');

-- Q4: Inserting sample data for Guest table
INSERT INTO Guest
	VALUES('234989323', 'Dennis Ho', '810 Sunnyside Ave');
	
INSERT INTO Guest
	VALUES('223338333', 'Bruce Link', '3456 Java Lane');
	
INSERT INTO Guest
	VALUES('238768745', 'Ernest Lee', '3456 Java Lane');

-- Q4: Inserting sample data for Booking table
INSERT INTO Booking
	VALUES('HC5678578', '234989323', '2011-09-05', '2011-10-01', '54');
	
INSERT INTO Booking
	VALUES('HM2927848', '223338333', '2012-01-28', '2012-01-29', '89');
	
INSERT INTO Booking
	VALUES('FS3938237', '238768745', '2012-01-27', '2012-02-05', '100');

COMMIT;

-- Q5(A): Altering constraints of Room table for a new room type
ALTER TABLE Room
	DROP
	CONSTRAINT chk_room_type;

ALTER TABLE Room
	ADD 
	CONSTRAINT chk_room_type CHECK(type IN('Single', 'Double', 'Family', 'Deluxe'));

-- Q5(B): Adding discount column to Room table
ALTER Table Room
	ADD
	discount VARCHAR(2) DEFAULT 0 NOT NULL;

ALTER Table Room
	ADD
	CONSTRAINT chk_discount CHECK(discount BETWEEN 0 AND 30);

-- Q6(A): Increasing price of Double room by 15%
UPDATE Room
	SET price = (price * 1.15)
	WHERE type = 'Double'
	AND hotelNo = 'HC5678578';

-- Q6(B): Booking guest decides to arrive earlier and stay longer
UPDATE Booking
	SET dateFrom = '2012-01-25'
	WHERE hotelNo = 'HM2927848'
	AND guestNo = '223338333';

UPDATE Booking
	SET dateTo = '2012-02-14'
	WHERE hotelNo = 'HM2927848'
	AND guestNo = '223338333';

-- Q7(A): Creating OldBooking table
CREATE TABLE OldBooking
(hotelNo	CHAR (9)		NOT NULL
,guestNo	CHAR (9)		NOT NULL
,dateFrom	DATE			NOT NULL
,dateTo		DATE			NOT NULL
,roomNo		VARCHAR (3)	    NOT NULL
,CONSTRAINT PKOldBooking PRIMARY KEY (hotelNo, guestNo, dateFrom)
);

-- Q7(B): Insert old records from Booking table to OldBooking table
INSERT INTO OldBooking
	VALUES('HC5678578', '234989323', '2011-09-05', '2011-10-01', '54');
	
DELETE FROM Booking
	WHERE dateTo < '2012-01-01';
	
SPOOL OFF
