#include <fstream>
#include <string>
#include "./include/httplib.h"

std::string ReadHtmlFile(std::string path) {
	std::string zz, final;
	std::ifstream fileRead(path);

	while (std::getline(fileRead, zz)) {
		final += zz;
	}

	fileRead.close();

	return final;
}

int main() {
	httplib::Server scr;

	scr.Get("/", [](const httplib::Request &, httplib::Response &res) {	
		res.set_content(ReadHtmlFile("./Calendar.html"), "text/html");
	});

	scr.listen("0.0.0.0", 8080);

	return 0;
}
