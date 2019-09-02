#include <iostream> 
#include <string>



class Message
{
protected:
    std::string content;
public:
    void setContent(std::string content)
    {
        this->content = content;
    }

   std::string printMessage () {
    	return content;
    }
};


class Mailer
{
protected:
     Message message;
public:
    Mailer(Message& message)
    {
        this->message = message;
    }
    Message& sendMessage(){
        return (this->message);
    }
};

int main() {
	Message* msg = new Message();

	msg->setContent("bobContent\n");
	Mailer* bobMailer = new Mailer(*msg);

	msg->setContent("joeContent\n");
	Mailer* joeMailer = new Mailer(*msg);

	std::cout << "bobMailer : " << bobMailer->sendMessage().printMessage() << std::endl;
	std::cout << "joeMailer : " << joeMailer->sendMessage().printMessage() << std::endl;

	return 0;
}
