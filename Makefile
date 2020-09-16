CC = cl
FLAGS = /std:c++17 /WX /EHsc
OBJECTS = PPlot.obj SVGPainter.obj util.obj test.obj main.obj 

assignment2: $(OBJECTS)
	$(CC) /Fe"assignment2" $(OBJECTS)

PPlot.obj: lib\PPlot.cpp lib\PPlot.h
	$(CC) $(FLAGS) /c lib\PPlot.cpp

SVGPainter.obj: lib\SVGPainter.cpp lib\SVGPainter.h
	$(CC) $(FLAGS) /c lib\SVGPainter.cpp

util.obj: src\util.cpp src\util.h src\search.h
	$(CC) $(FLAGS) /c src\util.cpp

test.obj: src\test.cpp src\search.h src\util.h
	$(CC) $(FLAGS) /I lib\ -c src\test.cpp

main.obj: src\main.cpp
	$(CC) $(FLAGS) /I lib\ -c src\main.cpp

clean:
	del assignment2.exe *.obj *.svg
