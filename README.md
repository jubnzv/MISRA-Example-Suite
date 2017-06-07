MISRA C:2012 Examples from MISRA C:2012 document

Release: 2016-01-01 

Published by 
HORIBA MIRA Limited, Watling Street, Nuneaton, Warwickshire CV10 0TU UK
www.misra.org.uk

Copyright MIRA Limited 2013, 2014, 2016

Purpose
=======
This suite of files is intended to illustrate issues addressed by the MISRA C rules as expressed in:

   MISRA C:2012 Guidelines for the use of the C language in critical systems,
      ISBN 978-1-906400-10-1 paperback and ISBN 978-1-906400-11-8 PDF.

The examples are mainly taken from the example sections in the MISRA C:2012 guidelines. It is not intended to be an exhaustive test suite and should not be used as such.

Implementation
==============
One (or more) files exist for each guideline within the suite. Where no examples are appropriate, the file will state that no example is provided for that guideline.

The file "R_xx_yy.c" illustrates MISRA C:2012, rule xx.yy. For example, R_20_04.c illustrates Rule 20.4 and D_04_05.c illustrates Directive 4.5.

The guidelines that are marked with "System" analysis scope are designed to be analysed across translation units and so may not produce an appropriate violation if run as a single file. To aid analysis there are two additional files for each section in the guidelines. For example R_08_system.c contains a "main" function that calls the external functions for rules in section 8. R_08_support.c is a second call to those functions and exists to minmize the number of Rule 8.7. violations.


Version Control
===============
Each version of the exemplar suite is released in a single ZIP file. An MD5 checksum is provided for each Released ZIP file. Each file within a release will contain a record of the Last Modified Date for that file. To ensure that you have a valid copy of the latest release, please download from the MISRA website.

Limitations 
===========
The examples have been written assuming 32-bit integer word size, i.e. char is 8-bit, short is 16-bit, int is 32-bit and long is 64-bit. If this is used on a 16-bit integer machine, additional issues may be reported.

Results
=======
Files contain a number of C language statements. These are: 
a) support statements,
b) "Compliant" examples,
c) "Non-compliant" examples.
 
A "Compliant" example is a construct that should not generate a warning message.
A "Non-compliant" example is a construct that should generate a warning message. The exact location of this warning is permitted to be tool dependent.

It is not always possible to avoid cross-talk between rules, so some files will violate multiple rules. In particular, no attempt has been made to provide definitions for all external functions or objects (R.8.6), nor is there always more than one use of such identifiers (R.8.7). 

Tools may also generate additional messages. 

Feedback
========
Feedback may be provided via the MISRA C Forum.

Legal Disclaimer
================
Adherence to the requirements of MISRA C does not in itself ensure error-free robust software or guarantee portability and re-use.
Compliance with the requirements of MISRA C, or any subsequently published modification, does not of itself confer immunity from legal obligations.

No warranty or implied warranty is provided with this set of examples.
The set of examples may not be error free and it is not guaranteed that the use of the set of examples is fit for purpose.

License
=======
The MISRA C:2012 document examples consists of all files released in this compressed directory.

A license is granted for single-user personal use on a single computer only.

No permission is given for the distribution of these files, or any derivatives outside of your organisation. This includes but is not exclusively limited to making the copy available to others by email, placing it on a server for access by internet, printing and distributing hardcopies, or distribution with a tool. No public claims of any kind can be made under this licence. Any such use or claim constitutes an infringement of copyright and license.

Please contact MISRA for further details, including alternative licensing schemes.

Release History
===============
2014-01-13 1st Release
