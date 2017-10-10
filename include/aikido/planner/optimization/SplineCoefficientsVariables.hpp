#ifndef AIKIDO_PLANNER_OPTIMIZATION_OPTIMIZATIONSPLINE_HPP_
#define AIKIDO_PLANNER_OPTIMIZATION_OPTIMIZATIONSPLINE_HPP_

#include <memory>

#include <dart/optimizer/optimizer.hpp>

#include "aikido/planner/optimization/OptimizationVariables.hpp"
#include "aikido/trajectory/Spline.hpp"

namespace aikido {
namespace planner {
namespace optimization {

class SplineCoefficientsVariables : public TrajectoryOptimizationVariables,
                                    public trajectory::Spline
{
public:
  SplineCoefficientsVariables() = default;

  ~SplineCoefficientsVariables() = default;

  std::size_t getDimension() const override;

  void setVariables(const Eigen::VectorXd& variables) override;

  void getVariables(Eigen::VectorXd& variables) const override;

protected:
private:
};

} // namespace optimization
} // namespace planner
} // namespace aikido

#endif // AIKIDO_PLANNER_OPTIMIZATION_OPTIMIZATIONSPLINE_HPP_
