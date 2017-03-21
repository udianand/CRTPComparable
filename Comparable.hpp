
#ifndef Comparable_h
#define Comparable_h

template <typename Derived>
class Comparisons
{
};


// == operator implementation
template <typename Derived>
bool operator==(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) noexcept
{
    const Derived& d1 = static_cast<const Derived&>(o1);
    const Derived& d2 = static_cast<const Derived&>(o2);
    
    return !(d1 < d2) && !(d2 < d1);
}

// != operator implementation
template <typename Derived>
bool operator!=(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) noexcept
{
    return !(o1 == o2);
}

// > operator implementation. Checks if d1 is greater than d2
template <typename Derived>
bool operator>(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) noexcept
{
    const Derived& d1 = static_cast<const Derived&>(o1);
    const Derived& d2 = static_cast<const Derived&>(o2);
    
    return !(d1 < d2) && !(o1 == o2);
}

// <= operator implementation
template <typename Derived>
bool operator <=(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) noexcept
{
    return !(o1 > o2);
}

// >= operator implementation
template <typename Derived>
bool operator >= (const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) noexcept
{
    const Derived& d1 = static_cast<const Derived&>(o1);
    const Derived& d2 = static_cast<const Derived&>(o2);
    
    return !(d1 < d2);
}



struct Person: public Comparisons<Person>
{
    int size;
};

bool operator<(Person const& p1, Person const& p2)
{
    return (p1.size < p2.size);
}

/*class Person : public Comparisons<Person>
{
public:
    Person(std::string name_, unsigned age_)
    : name(name_), age(age_)
    {}
    
    friend bool operator<(const Person& p1, const Person& p2);

private:
    std::string name;
    unsigned age;
};


bool operator<(const Person& p1, const Person& p2)
{
    return p1.age < p2.age;
}*/


#endif /* Comparable_h */
