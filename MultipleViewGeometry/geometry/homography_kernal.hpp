#ifndef HOMOGRAPHY_KERNAL_HPP
#define HOMOGRAPHY_KERNAL_HPP

#include <vector>

/**
 * 这里两个头文件先不包含，看会出现什么错误，缺什么数据结构或其他*/

namespace openMVG{
namespace homography{
namespace kernal{
	
	struct FourPointSolver{
		enum{ MINIMUM_SAMPLES = 4 };
		enum{ MAX_MODELS = 1 };
		/*
		 * Compute the homography that transforms x to y with the Direct Linear Transform
		 * \param x A 2xN matrix of column vector
		 * \param y A 2xN matrix of column vector
		 * \param Hs A vector into which the computed homography is stored
		 *
		 * The estimated homography should approximately hold the condition y = Hx
		 * */

		static void Solve(const Mat &x, const Mat &y, std::vector<Mat3> *Hs);
	};

	//should be distributed as Chi-squared with k = 2 ?->表示应该能通过卡方检验
	struct AsysmetricError{
		static double Error(const Mat &H, const Vec2 &x, const Vec2 &y){
			return (y - Vec3(H*x.homogenerous()).hnormalized()).squaredNorm();
		}
	};
	
	//Kernel that works on original data point
	using UnnormalizedKernel = two_view::kernel::Kernel<FourPointSolver, AsymmetricError, Mat3>;

	//By default use the normalized version for increasd robustness
	using Kernel = two_view::kernel::Kernel<two_view::kernel::NormalizedSolver<FourPointSolver, UnnormalizerI>, AsymmetricError, Mat3>;

}	//namespace kernel
}	//namespace homography
}	//namespace openMVG
#endif
