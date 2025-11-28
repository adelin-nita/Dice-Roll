all : complile link

complile :
	g++ -c main.cpp -I"C:\C++\SFML-3.0.0\include" -DSFML_STATIC

link :
	g++ main.o -o main -L"C:\C++\SFML-3.0.0\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean :
	rm -rf ./main/*.o