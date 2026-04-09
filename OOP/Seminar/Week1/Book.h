#pragma once
enum class Genre
{
	Classic, 
	SciFi, 
	Fantasy, 
	Romance, 
	Crime, 
	NonFiction, 
	Educational, 
	Other
};

class Book
{
private:
	static constexpr size_t MAX_SIZE = 50;
	char title[MAX_SIZE] = "";
	char author[MAX_SIZE] = "";
	unsigned short publicationYear = 0;
	Genre genre = Genre::Other;

	void setTitle(const char* title);
	void setAuthor(const char* author);
public:
	Book(const char* title, const char* author, const unsigned short publicationYear, const Genre genre);

	Book(const Book& other) = delete;
	Book(Book&& other) = delete;
	Book& operator=(const Book& other) = delete;
	Book& operator=(Book&& other) = delete;

	const char* getTitle() const;
	const char* getAuthor() const;
	unsigned short getPublicationYear() const;
	Genre getGenre() const;
};

