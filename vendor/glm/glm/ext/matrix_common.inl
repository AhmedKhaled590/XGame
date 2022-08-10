<<<<<<< HEAD
#include "../matrix.hpp"

namespace glm
{
	template<length_t C, length_t R, typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER mat<C, R, T, Q> mix(mat<C, R, T, Q> const& x, mat<C, R, T, Q> const& y, U a)
	{
		return mat<C, R, U, Q>(x) * (static_cast<U>(1) - a) + mat<C, R, U, Q>(y) * a;
	}

	template<length_t C, length_t R, typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER mat<C, R, T, Q> mix(mat<C, R, T, Q> const& x, mat<C, R, T, Q> const& y, mat<C, R, U, Q> const& a)
	{
		return matrixCompMult(mat<C, R, U, Q>(x), static_cast<U>(1) - a) + matrixCompMult(mat<C, R, U, Q>(y), a);
	}
}//namespace glm
=======
#include "../matrix.hpp"

namespace glm
{
	template<length_t C, length_t R, typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER mat<C, R, T, Q> mix(mat<C, R, T, Q> const& x, mat<C, R, T, Q> const& y, U a)
	{
		return mat<C, R, U, Q>(x) * (static_cast<U>(1) - a) + mat<C, R, U, Q>(y) * a;
	}

	template<length_t C, length_t R, typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER mat<C, R, T, Q> mix(mat<C, R, T, Q> const& x, mat<C, R, T, Q> const& y, mat<C, R, U, Q> const& a)
	{
		return matrixCompMult(mat<C, R, U, Q>(x), static_cast<U>(1) - a) + matrixCompMult(mat<C, R, U, Q>(y), a);
	}
}//namespace glm
>>>>>>> 31c2538aad6a7e0f97036ec08c7eedea29b76aaa
