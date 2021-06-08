#include <iostream>
#include <string>
#include <map>
#include "helper.h"
class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;	// friend class : 해당 클래스의 멤버 함수에서는
								//                Image의 private에 접근할수 있다
};
// Image 객체를 만들고 관리하는 역활을 수행하는 클래스
class ImageFactory
{
	std::map<std::string, Image*> image_map;

	MAKE_SINGLENTON(ImageFactory)
public:
	Image* Create(std::string url)
	{
		Image* img = image_map[url];

		if (img == nullptr)
		{
			img = new Image(url);
			image_map[url] = img;
		}
		return img;
	}
};
int main()
{
	ImageFactory& factory = ImageFactory::getInstance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();
}



