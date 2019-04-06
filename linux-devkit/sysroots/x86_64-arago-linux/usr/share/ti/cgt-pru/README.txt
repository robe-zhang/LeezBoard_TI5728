TI PRU C/C++ CODE GENERATION TOOLS
2.2.1 Release Notes
December 2017

===============================================================================
Contents
===============================================================================
1) Support Information
2) New Features
2.1) Array Output Format for Hex Utility
2.2) New Assembler Option
2.3) Support abbreviated formats for SET/CLR instructions
3) Option Cleanup

-------------------------------------------------------------------------------
1.  Support Information
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
1.1) List of Fixed and Known Defects
-------------------------------------------------------------------------------

The DefectHistory.txt file has been replaced with the two files
Open_defects.html and Closed_defects.html. For open bugs, a status of Open or
Accepted means that the bug has not been examined yet, whereas a status of
Planned means that an evaluation or fix is in progress.

-------------------------------------------------------------------------------
1.2) Compiler Wiki
-------------------------------------------------------------------------------

A Wiki has been established to assist developers in using TI Embedded
Processor Software and Tools.  Developers are encouraged to read and
contribute to the articles.  Registered users can update missing or
incorrect information.  There is a large section of compiler-related
material.  Please visit:

http://processors.wiki.ti.com/index.php?title=Category:Compiler

-------------------------------------------------------------------------------
1.3) TI E2E Community
-------------------------------------------------------------------------------

Questions concerning TI Code Generation Tools can be posted to the TI E2E
Community forums.  The "Development Tools" forum can be found at:

http://e2e.ti.com/support/development_tools/f/default.aspx

-------------------------------------------------------------------------------
1.4) Defect Tracking Database
-------------------------------------------------------------------------------

Compiler defect reports can be tracked at the Development Tools bug
database, SDOWP. The log in page for SDOWP, as well as a link to create
an account with the defect tracking database is found at:

https://cqweb.ext.ti.com/pages/SDO-Web.html

A my.ti.com account is required to access this page.  To find an issue
in SDOWP, enter your bug id in the "Find Record ID" box once logged in.
To find tables of all compiler issues click the queries under the folder:

"Public Queries" -> "Development Tools" -> "TI C-C++ Compiler"

With your SDOWP account you can save your own queries in your
"Personal Queries" folder.


-------------------------------------------------------------------------------
2. New Features
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
2.1) Array Output Format for Hex Utility
-------------------------------------------------------------------------------
This release adds support for the --array option to the Hex Utility for
specifying array output format. Output arrays contain data in initialized
sections of an executable file. Arrays may be compiled along with a host
program, such as ARM, and used to initialize the PRU at runtime.

2.1.1) Array Formation
----------------------
Arrays are formed by collecting initialized sections from the input executable. There are two ways arrays are formed:
a. Using the ROMS directive. Each memory range that is given in the ROMS 
   directive denotes an array. The romname is the array name. The origin and 
   length parameters are required. The memwidth, romwidth, and files parameters
   are invalid and ignored.
b. Default Array Formation. If no ROMS directive is given, arrays are formed 
   by combining initialized sections within each page, starting with the first
   initialized section. Arrays will reflect any gaps that exist between
   sections. The default array names for test.out are 

2.1.2) Array names
------------------
When ROMS directive is used, romnames are the default array names. When ROMS
directive is not used, prefixes "executable_name_image_" are used for array
names. For example, the default array names for test.out are test_image_0[]
and test_image_1[] mapping to data on pages 0 and 1 respectively. Default 
prefixes for array names may be overridden by specifying
array:name_prefix="prefix"

2.1.3) Data Types for Array Elements
------------------------------------
The default type for page 0 array elements is uint32_t while the type for
page 1 array elements is uint8_t. However, the type for page0 array elements
may be changed to uint8_t by specifying option array:page0_type_size=8.

-------------------------------------------------------------------------------
2.2) New Assembler Option
-------------------------------------------------------------------------------
A new assembler option --code_address_listing_unit=byte|word was added for
selecting byte or word unit for code section program counter field in assembler
listing file. 

-------------------------------------------------------------------------------
2.3) Support abbreviated formats for SET/CLR instructions
-------------------------------------------------------------------------------
This release adds support for SET/CLR Rn.tx which is equivalent to 
SET/CLR Rn,Rn.tx with the same source and destination register.

-------------------------------------------------------------------------------
3) Option Cleanup
-------------------------------------------------------------------------------
In this release we removed several options that were either duplicates or
unnecessary. For an overview of the changes please see
http://processors.wiki.ti.com/index.php/Compiler_option_cleanup
