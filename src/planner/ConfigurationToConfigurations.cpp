#include "aikido/planner/ConfigurationToConfigurations.hpp"

#include "aikido/constraint/Testable.hpp"

namespace aikido {
namespace planner {

//==============================================================================
ConfigurationToConfigurations::ConfigurationToConfigurations(
    statespace::ConstStateSpacePtr stateSpace,
    const statespace::StateSpace::State* startState,
    const GoalStates& goalStates,
    constraint::ConstTestablePtr constraint)
  : Problem(std::move(stateSpace), std::move(constraint))
  , mStartState(stateSpace->cloneState(startState))
{
  for (const statespace::StateSpace::State* goal : goalStates)
  {
      mGoalStates.push_back(stateSpace->cloneState(goal));
  }
}

//==============================================================================
const std::string& ConfigurationToConfigurations::getType() const
{
  return getStaticType();
}

//==============================================================================
const std::string& ConfigurationToConfigurations::getStaticType()
{
  static std::string name("ConfigurationToConfigurations");
  return name;
}

//==============================================================================
const statespace::StateSpace::State*
ConfigurationToConfigurations::getStartState() const
{
  return mStartState;
}

//==============================================================================
std::size_t ConfigurationToConfigurations::getNumGoalStates() const
{
  return mGoalStates.size();
}

//==============================================================================
const ConfigurationToConfigurations::GoalStates&
ConfigurationToConfigurations::getGoalStates() const
{
  std::vector<const statespace::StateSpace::State*> pointerStates;
  for (size_t idx = 0; idx < mGoalStates.size(); idx++)
  {
    pointerStates.push_back(mGoalStates.at(idx).getState());
  }

  return pointerStates;
}

} // namespace planner
} // namespace aikido
