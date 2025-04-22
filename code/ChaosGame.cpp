// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>

//EXTRA CREDIT PORTION COMMENTED OUT
//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	srand(time(0));

	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);

	Font font;
        if (!font.loadFromFile("fonts/Ubuntu-Regular.ttf"))
        {
                return 1;
        }

	Text text;
	text.setFont(font);
	
	//text.setString("Click on 4 points for the square fractal.");
	
	text.setString("Click on three points for the vertices.");
	text.setCharacterSize(24);
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;
	Vector2f repeat, rv;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	
			    if(vertices.size() < 3)
				    
			    //if(vertices.size() < 4)
			    //if you want to run square fractal! uncomment < 4 and comment out < 3
				    
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			    else if(points.size() == 0)
			    {
				///fourth click
				///push back to points vector
				points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
		    ///generate more point(s)
		    ///select random vertex
		    ///calculate midpoint between random vertex and the last point in the vector
		    ///push back the newly generated coord.

		    //EXTRA CREDIT CODE. uncomment
		    //do {
			
		    rv = vertices[rand() % vertices.size()];

		    //extra credit code. uncomment
		    //} while (repeat == rv);
		    repeat = rv; 
			
		    Vector2f midpoint((rv.x + points[points.size() - 1].x) / 2.0, (rv.y + points[points.size() - 1].y) / 2.0);

		    points.push_back(midpoint); 
		}
	
		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();

		window.draw(text);

		for(long unsigned int i = 0; i < vertices.size(); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    rect.setFillColor(Color::Blue);
		    window.draw(rect);
		}
		///TODO:  Draw points
		for(long unsigned int i = 0; i < points.size(); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(points[i].x, points[i].y));
		    rect.setFillColor(Color::Red);
		    window.draw(rect);
		}	
		window.display();
	}
}
