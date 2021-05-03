using ProblemSolving.Interface;
using System;
using Xunit;

namespace ProblemSolving.Test
{
    public class NextGreaterNumberProblemTest
    {
        private IProblemSolve _problemSolve;
        public NextGreaterNumberProblemTest()
        {
            _problemSolve = new NextGreaterNumberProblem();
        }
        [Fact]
        public void ShouldReturn3410()
        {
            //Arrange
            var input = 3401;

            //Act
            var actual = _problemSolve.SolveProblem(input);

            //Assert
            Assert.Equal(3410, actual);
        }
        [Fact]
        public void ShouldReturnWrongNumberOfParameters()
        {
            var ex = Assert.Throws<Exception>(() => _problemSolve.SolveProblem(123, 321));
            Assert.Equal("Wrong number of arguments", ex.Message);
        }
        [Fact]
        public void ShouldReturnNotNullException()
        {
            var ex = Assert.Throws<Exception>(() => _problemSolve.SolveProblem(null));
            Assert.Equal("The number shouldn't be null", ex.Message);
        }
        [Fact]
        public void ShouldReturnInvalidNumberException()
        {
            var ex = Assert.Throws<Exception>(() => _problemSolve.SolveProblem("123evb"));
            Assert.Equal("Invalid number", ex.Message);
        }
    }
}
