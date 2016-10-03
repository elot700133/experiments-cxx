#include <iostream>
#include <tuple>
#include <functional>
///#include <placeholder>

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
template <typename ClassType, typename ReturnType, typename... Args, typename ClassObj, typename Placeholder>
struct function_traits<std::_Bind<std::_Mem_fn<ReturnType(ClassType::*)(Args...)>(ClassObj, Placeholder)>>
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

class Handler
{
  public:
    long handle(const Msg&){ return long(10); }
};

template<class T>
void foo(T lambda)
{
    typedef function_traits<decltype(lambda)> traits;
    typename traits::result_type rt;
    typedef typename traits::template arg<0>::type const_msg_reference;
    typedef typename std::remove_reference<const_msg_reference>::type const_msg;
    typedef typename std::remove_const<const_msg>::type msg_type;
    static_assert(std::is_same<long, typename traits::result_type>::value, "err");
    //static_assert(std::is_same<const Msg&, template traits::typename template arg<0>::type>::value, "err");

    //typedef traits::arg<0>::type const_msg_reference;
    //typedef std::remove_reference<const_msg_reference>::type const_msg;
    //typedef std::remove_const<const_msg>::type msg_type;
    msg_type m;
    m.i = 3;
    printf("%d\n", m.i);
}

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
    //printf("%d\n", m.i);

    //foo(lambda);

    Handler h;
    foo(std::bind(&Handler::handle, &h, std::placeholders::_1));
    //foo([](){});

    return 0;
}
