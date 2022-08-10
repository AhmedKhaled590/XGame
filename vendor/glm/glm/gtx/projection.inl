<<<<<<< HEAD
/// @ref gtx_projection

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType proj(genType const& x, genType const& Normal)
	{
		return glm::dot(x, Normal) / glm::dot(Normal, Normal) * Normal;
	}
}//namespace glm
=======
/// @ref gtx_projection

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType proj(genType const& x, genType const& Normal)
	{
		return glm::dot(x, Normal) / glm::dot(Normal, Normal) * Normal;
	}
}//namespace glm
>>>>>>> 31c2538aad6a7e0f97036ec08c7eedea29b76aaa
