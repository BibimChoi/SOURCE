#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	// private 생성자 : 외부에서 자유롭게 객체를 만드는 것을 막는다.
	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// 자신의 객체를 만드는 static 멤버 함수 - 아주 유명한 기술
	static Image* Create(std::string url)
	{
		Image* img = image_map[url];
		
		if (img == nullptr)
		{
			img = new Image(url);
			image_map[url] = img;
		}

		return img;
	}
	static std::map<std::string, Image*> image_map; 
};
std::map<std::string, Image*> Image::image_map;


int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();
}



