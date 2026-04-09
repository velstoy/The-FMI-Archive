#include "Book.h"
#include <cstring>

void Book::setTitle(const char* title)
{
	strcpy_s(this->title, MAX_SIZE, title);
}

void Book::setAuthor(const char* author)
{
	strcpy_s(this->author, MAX_SIZE, author);
}

Book::Book(const char* title, const char* author, const unsigned short publicationYear, const Genre genre) 
	: publicationYear(publicationYear), genre(genre)
{
	setTitle(title);
	setAuthor(author);
}

const char* Book::getTitle() const
{
	return title;
}

const char* Book::getAuthor() const
{
	return author;
}

unsigned short Book::getPublicationYear() const
{
	return publicationYear;
}

Genre Book::getGenre() const
{
	return genre;
}
