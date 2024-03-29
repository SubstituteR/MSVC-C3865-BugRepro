#include <stdio.h>
#include <type_traits>
#include <typeinfo>

template<class A, class B, class C>
struct are_same_three : std::false_type {};

template<class A>
struct are_same_three<A, A, A> : std::true_type {};

template<class A, class B, class C>
inline constexpr bool are_same_three_v = are_same_three<A, B, C>::value;

//#define bugcheck //uncomment to enable defect.

#ifdef bugcheck
#define cc __thiscall
#else
#define cc __stdcall
#endif

using derived_1 = void cc();
using derived_2 = derived_1*;

int main()
{
	void(cc * base_type)();
	derived_1* first_order;
	derived_2 second_order;
	static_assert(are_same_three_v<decltype(base_type), decltype(first_order), decltype(second_order)>, "Types are not the same.");
}
