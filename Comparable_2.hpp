
#ifndef Comparable_h
#define Comparable_h

template <typename Derived>
struct Comparisons
{
    bool operator==(const Comparisons<Derived>& o2) const noexcept
    {
        const Derived& d1 = static_cast<const Derived&>(*this); //9
        const Derived& d2 = static_cast<const Derived&>(o2); //8
        
        return !(d1 < d2) && !(d2 < d1);
    }
    

    bool operator!=(const Comparisons<Derived>& o1) const noexcept
    {
        return !(o1 == *this);
    }
    
    bool operator>(const Comparisons<Derived>& o2) const noexcept
    {
        const Derived& d1 = static_cast<const Derived&>(*this);
        const Derived& d2 = static_cast<const Derived&>(o2);
    
        return (d2 < d1);
    }
    
    bool operator <=(const Comparisons<Derived>& o2) const noexcept
    {
        const Derived& d1 = static_cast<const Derived&>(*this);
        const Derived& d2 = static_cast<const Derived&>(o2);
    
        return !(d2 < d1);
    }
    
    bool operator >= (const Comparisons<Derived>& o2) const noexcept
    {
        const Derived& d1 = static_cast<const Derived&>(*this);
        const Derived& d2 = static_cast<const Derived&>(o2);
       
        return !(d1 < d2);
    }

};



struct Person: public Comparisons<Person>
{
    int size;
    
};

bool operator<(Person const& p1, Person const& p2)
{
    return (p1.size < p2.size);
}

#endif /* Comparable_h */
