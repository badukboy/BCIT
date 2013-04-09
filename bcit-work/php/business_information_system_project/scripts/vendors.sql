DROP TABLE IF EXISTS vendors;
CREATE TABLE vendors 
(
`id` varchar(3) NOT NULL,
`vendorname` varchar(80),
`status` varchar(1),
	PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO vendors(id, vendorname, status) 
	VALUES ('001', 'HomeSense', 'A');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('002', 'Staples', 'A');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('003', 'Home Depot', 'A');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('004', 'IKEA', 'A');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('005', 'Lowes', 'A');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('006', 'Sears', 'D');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('007', 'Tesco', 'D');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('008', 'Target', 'D');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('009', 'Walmart', 'A');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('010', 'The Brick', 'A');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('011', 'Ashley Furniture Home', 'D');
INSERT INTO vendors(id, vendorname, status) 
	VALUES ('012', 'Canadian Tire', 'A');