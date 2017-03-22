
#ifndef Comparable_h
#define Comparable_h

template <typename Derived>
struct Comparisons
{
    bool operator==(const Comparisons<Derived>& o1) const noexcept
    {
        const Derived& d1 = static_cast<const Derived&>(o1); //8
        const Derived& d2 = static_cast<const Derived&>(*this); //9
        
        return !(d1 < d2) && !(d2 < d1);
    }
    

    bool operator!=(const Comparisons<Derived>& o1) const noexcept
    {
        return !(o1 == *this);
    }
    
    bool operator>(const Comparisons<Derived>& o1) const noexcept
    {
        const Derived& d1 = static_cast<const Derived&>(o1);
        const Derived& d2 = static_cast<const Derived&>(*this);
        
        //std::cout << "d1 G: " << d1.size << std::endl; // 8
        //std::cout << "d2 G: " << d2.size << std::endl; // 9
        
        return (d2 < d1);
    }
    
    bool operator <=(const Comparisons<Derived>& o1) const noexcept
    {
        const Derived& d1 = static_cast<const Derived&>(o1);
        const Derived& d2 = static_cast<const Derived&>(*this);
        
        //std::cout << "d1 LE: " << d1.size << std::endl;
        //std::cout << "d2 LE: " << d2.size << std::endl;

        return !(d2 < d1);
    }
    
    bool operator >= (const Comparisons<Derived>& o1) const noexcept
    {
        const Derived& d1 = static_cast<const Derived&>(o1);
        const Derived& d2 = static_cast<const Derived&>(*this);
        
        return !(d1 < d2);
    }

};


// == operator implementation
/*template <typename Derived>
bool operator==(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) noexcept
{
    const Derived& d1 = static_cast<const Derived&>(o1);
    const Derived& d2 = static_cast<const Derived&>(o2);
    
    return !(d1 < d2) && !(d2 < d1);
}*/

// != operator implementation
/*template <typename Derived>
bool operator!=(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) noexcept
{
    return !(o1 == o2);
}*/

// > operator implementation. Checks if d1 is greater than d2
/*template <typename Derived>
bool operator>(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) noexcept
{
    const Derived& d1 = static_cast<const Derived&>(o1);
    const Derived& d2 = static_cast<const Derived&>(o2);
    
    return !(d1 < d2) && !(o1 == o2);
}*/

// <= operator implementation
/*template <typename Derived>
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
*/


struct Person: public Comparisons<Person>
{
    int size;
    
};

bool operator<(Person const& p1, Person const& p2)
{
    return (p1.size < p2.size);
}

#endif /* Comparable_h */
