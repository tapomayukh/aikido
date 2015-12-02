#ifndef R3_PATH_TRAJECTORY_H_
#define R3_PATH_TRAJECTORY_H_
#include <boost/shared_ptr.hpp>

namespace r3 {
namespace path {


class Trajectory
{
public:
  using Index = int;
  using Scalar = double;
  using Vector = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>;

  virtual ~Trajectory() = default;

  virtual Index getNumOutputs() const = 0;

  virtual Index getNumDerivatives() const = 0;

  virtual Scalar getDuration() const = 0;

  virtual Vector evaluate(Scalar _t, Index _derivative) const = 0;
};


using TrajectoryPtr = boost::shared_ptr<Trajectory>;
using ConstTrajectoryPtr = boost::shared_ptr<const Trajectory>;


} // namespace path
} // namespace r3

#endif // ifndef R3_PATH_TRAJECTORY_H_
