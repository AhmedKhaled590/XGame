<<<<<<< HEAD
/// @ref gtx_perpendicular

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType perp(genType const& x, genType const& Normal)
	{
		return x - proj(x, Normal);
	}
}//namespace glm
=======
/// @ref gtx_perpendicular

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType perp(genType const& x, genType const& Normal)
	{
		return x - proj(x, Normal);
	}
}//namespace glm
>>>>>>> 31c2538aad6a7e0f97036ec08c7eedea29b76aaa
