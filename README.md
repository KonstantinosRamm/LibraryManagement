# LibraryManagement

## This project focuses on developing a Library Management System to practice and enhance my knowledge of data structures, particularly hash tables. The system implements the Cuckoo Hashing algorithm for efficient storage and management of books. Additionally, the project aims to improve my design skills using UML, serving as a personal reference for tracking books I’ve read. Although I could easily use ready-made data structures from the STL, I’ve chosen to implement them myself in order to deepen my understanding and further refine my skills.

## The library is designed to read books from Library.txt within the same directory as the binary of the program.It consists of a total of 3 classes and 1 data struct
* HashTable: The basic feature here is that it consists of 2 vectors both of which store only one element at each index .The conflicts managed with cuckoo hashing .thats the reason behind the 2 vectors.The tables
  also dynamically resize based on the load factor which is set to 75% as threshold.

* cuckoo: This class consists of the hashing algorithms and the main cuckoo hashing algorithm . It also contains 2 vectors used to detect cycles during each eviction .In case of a cycle a resize also occures and the tables will also resize

* Library is the main class which is created to abstract the other operations .The basic feature is 6 objects of HashTable class(stored as an array) that will allow us to handle searchin by multiple fields.We use 6 HashTables because the book struct has also 6 fields.

* book :the datastruct that stores information about the books and it consists of 6 Fields: Title,Author,Genre,ISBN,Year,Publisher

# Key Features

##
- Efficient Book Management: Utilize Cuckoo Hashing to ensure fast insertion, deletion, and search operations for managing book records.
- Track Books Read: Maintain a record of books you've read, including metadata such as title, author, and genre.
- UML Design: The system design is represented through UML diagrams, helping to improve skills in designing clear and structured system architectures.
- Implement Features such as : sorting the books based on a field like ISBN,Title,Author
- Use of Multiple Hash Tables for search By Multiple Fields
- Technologes: C++,Uml



  
  
