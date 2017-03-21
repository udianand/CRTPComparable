
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


#endif /* Comparable_h */
