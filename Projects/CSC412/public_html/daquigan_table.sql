-- phpMyAdmin SQL Dump
-- version 3.4.10.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Apr 23, 2015 at 04:42 AM
-- Server version: 5.5.32
-- PHP Version: 5.3.10-1ubuntu3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `student_csc412`
--

-- --------------------------------------------------------

--
-- Table structure for table `daquigan_table`
--

CREATE TABLE IF NOT EXISTS `daquigan_table` (
  `Disc` text NOT NULL,
  `Distributor` text NOT NULL,
  `Plastic` text NOT NULL,
  `Speed` int(20) NOT NULL,
  `Glide` int(10) NOT NULL,
  `Turn` int(10) NOT NULL,
  `Fade` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `daquigan_table`
--

INSERT INTO `daquigan_table` (`Disc`, `Distributor`, `Plastic`, `Speed`, `Glide`, `Turn`, `Fade`) VALUES
('Groove', 'Innova', 'Champion', 13, 6, -2, 2),
('Katana', 'Innova', 'Champion', 13, 5, -2, 3),
('Beast', 'Innova', 'Champion', 10, 5, -2, 2),
('Roadrunner', 'Innova', 'Star', 9, 5, -4, 1),
('Mako', 'Innova', 'Star', 4, 5, 0, 0),
('Shark', 'Innova', 'DX', 4, 4, 0, 2),
('Ion', 'MVP', 'Proton Soft', 3, 4, 0, 1),
('Anode', 'MVP', 'Neutron', 3, 3, 0, 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
