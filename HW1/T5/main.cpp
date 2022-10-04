#include <printf.h>

class Prism
{
public:
    virtual ~Prism() = default;

    virtual double Square() const = 0;

    double Volume() const
    {
        return height_ * Square();
    }

private:
    const double height_ = 0.5;
};

class Box : public Prism
{
public:
    Box(const double length, const double width) : length_(length), width_(width) {}

    double Square() const override
    {
        return length_ * width_;
    }

private:
    double length_;
    double width_;
};

class Cube : public Box
{
public:
    Cube(const double length) : Box(length, length), length_(length) {}

    double Square() const override
    {
        return length_ * length_;
    }

private:
    double length_;
};

int main()
{
    const Prism *p, *q, *r;
    Box a(0.5, 2), b(5, 0.2);
    Cube c(0.5);

    p = &a; q = &b; r = &c;

    printf("Squares : %3.3lf %3.3lf %3.3lf\n", p->Square(), q->Square(), r->Square());
    printf("Volumes : %3.3lf %3.3lf %3.3lf\n", p->Volume(), q->Volume(), r->Volume());

    return 0;
}
