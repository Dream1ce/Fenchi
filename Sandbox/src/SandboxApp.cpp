
#include<Fenchi.h>

class Sandbox : public Fenchi::Application
{
public:
	Sandbox() {}
	~Sandbox() {};
};


Fenchi::Application* Fenchi::CreateApplication()
{
	return new Sandbox();
}