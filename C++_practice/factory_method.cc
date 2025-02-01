#include <iostream>
#include <vector>  
using namespace std;

class Shape {
    public:
        virtual void draw() = 0;
        virtual ~Shape() {}
};

class Circle : public Shape {
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
    public:
        void draw() override{
            cout << "Drawing a Square" << endl;
        }
};

class ShapeFactory {
    public:
        virtual Shape* createShape() = 0;
        virtual ~ShapeFactory() {}
};

class CircleFactory : public ShapeFactory{
    public:
        Shape* createShape() override{
            return new Circle();
        }
};

class SquareFactory : public ShapeFactory{
    public:
        Shape* createShape() override{
            return new Square();
        }
};

int main(){
    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();

    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();

    circle->draw();
    square->draw();

    delete circleFactory;
    delete squareFactory;
    delete circle;
    delete square;

    return 0;
}