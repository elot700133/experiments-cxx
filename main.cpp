#include <iostream>
#include <tuple>

template <typename T>
struct function_traits
    : public function_traits<decltype(&T::operator())>
{};
// For generic types, directly use the result of the signature of its 'operator()'

template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const>
// we specialize for pointers to member function
{
    enum { arity = sizeof...(Args) };
    // arity is the number of arguments.

    typedef ReturnType result_type;

    template <size_t i>
    struct arg
    {
        typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
        // the i-th argument is equivalent to the i-th tuple element of a tuple
        // composed of those arguments.
    };
};

class Msg
{
  public:
  int i;
};
// test code below:
int main()
{
    auto lambda = [](const Msg& m) { return long(10); };

    typedef function_traits<decltype(lambda)> traits;

    static_assert(std::is_same<long, traits::result_type>::value, "err");
    static_assert(std::is_same<const Msg&, traits::arg<0>::type>::value, "err");

    typedef traits::arg<0>::type const_msg_reference;
    typedef std::remove_reference<const_msg_reference>::type const_msg;
    typedef std::remove_const<const_msg>::type msg_type;
    msg_type m;
    m.i = 3;
    printf("%d\n", m.i);

    return 0;
}
