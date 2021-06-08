// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// 자신을 만드는 static 멤버 함수 - 아주 유용하게 활용됩니다.
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



