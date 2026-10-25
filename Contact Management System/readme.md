# Contact Management System

Explicit original prompt available
In-memory C++

Primary sources: LeetCode Discuss — original problem statement · LinkedIn — recent Contact Search System report

# Problem statement

Design and implement a Contact Management System with the following functionality.

## Functional requirements
1. Add and update contacts.
2. Search contacts using partial-prefix or complete matches.
3. Support searching by first name.
4. Support searching by last name.
5. Support searching by phone number.
6. Display both the total number of matches and the matching contacts for every search.
7. Make first-name and last-name searches case-insensitive.
Explicit constraints and expectations
- Identify the entities and attributes needed by the system.
- Do not implement REST APIs.
- Do not build a user interface.
- Do not use a database or external data store; keep the data in memory.
- Test the functionality through unit tests.
- Follow SOLID, DRY and other good coding practices.
- Make the design modular and extensible for future requirements.
The original report describes a two-hour interview: approximately 15 minutes for the briefing, 90 minutes for coding and 15 minutes for explaining the implementation. A later backend-intern report describes a three-hour Contact Search round with starter code, so the allotted time varies by interview cycle. 



## What is not specified in the published prompt
Whether contacts need unique phone numbers, whether duplicate contacts are permitted, how phone numbers should be normalized, how results should be sorted, or whether partial matching means prefixes only or arbitrary substrings.

# Architecture Diagram
![Contact Management System UML](Contact%5FManager%5FUML.drawio.svg)