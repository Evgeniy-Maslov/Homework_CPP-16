#include <string>
#include <iostream>


class SimpleText
{
public:
	virtual void render(const std::string& data) const
	{
		std::cout << data;
	}
};


class DecoratedText : public SimpleText
{
public:
	SimpleText* _text_;
	DecoratedText(SimpleText* text) : _text_(text) {}
};

class ItalicText : public DecoratedText	
{
public:
	ItalicText(SimpleText* text) : DecoratedText(text) {}
	void render(const std::string& data)	
	{										
		std::cout << "<i>";					
		_text_->render(data);			
		std::cout << "</i>";
	}
};

class BoldText : public DecoratedText	
{
public:
	BoldText(SimpleText* text) : DecoratedText(text) {}
	void render(const std::string& data)	
	{										
		std::cout << "<b>";					
		_text_->render(data);			
		std::cout << "</b>";
	}
};

class Paragraph : public DecoratedText
{
public:
	Paragraph(SimpleText* text) : DecoratedText(text) {}
	void render(const std::string& data)	
	{										
		std::cout << "<p>";					
		_text_->render(data);			
		std::cout << "</p>";
	}
};

class Reversed : public DecoratedText
{
public:
	Reversed(SimpleText* text) : DecoratedText(text) {}
	void render(const std::string& data)
	{
		std::string revers_data = data;
		std::reverse(revers_data.begin(), revers_data.end());
		_text_->render(revers_data);
	}
};

class Link : public DecoratedText
{
public:
	Link(SimpleText* text) : DecoratedText(text) {}
	void render(const std::string& data_1, const std::string& data_2)
	{
		std::cout << "<a href = " + data_1 + ">";
		_text_->render(data_2);
		std::cout << "</a>";
	}
};

	
int main()
{
	auto simple_text = new SimpleText();
	simple_text->render("HTML code");
	std::cout << std::endl;
	auto italic_text = new ItalicText(simple_text);
	italic_text->render("HTML code italic style");
	std::cout << std::endl;
	auto bold_text = new BoldText(simple_text);
	bold_text->render("HTML code bold style");
	std::cout << std::endl;

	auto paragraph_text = new Paragraph(simple_text);
	paragraph_text->render("Hello world");
	std::cout << std::endl;
	auto reversed_text = new Reversed(simple_text);
	reversed_text->render("Hello world");
	std::cout << std::endl;
	auto link_text = new Link(simple_text);
	link_text->render("netology.ru", "Hello world"); 
	std::cout << std::endl;
	return 0;
}