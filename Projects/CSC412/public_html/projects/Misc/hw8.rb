# 1.
def conditional_demo
	number = rand(100)
	puts "number is " + number.to_s
	if number < 10
		puts "#{number.to_s} < 10"
	end

	if number < 50
		puts "#{number.to_s} < 50"
	else 
		puts "#{number.to_s} >= 50"
	end

	if number < 25
		puts "0 < #{number.to_s} < 25"
	elsif number < 50
		puts "25 <= " + number.to_s + " < 50"
	elsif number < 75
		puts "50 <= " + number.to_s + " < 75"
	else
		puts "75 <= " + number.to_s + " <= 100"
	end

	number = rand(1000)

	case 
	when number < 333
		puts "0 < " + number.to_s + " < 333"
	when number > 333  && number < 666
		puts "333 <= " + number.to_s + " < 666"
	else
		puts "666 <= " + number.to_s + " <= 1000"
	end
end

# 2.
def loop_iterator_demo
	puts "while:"
	while $i < 5 do 
		puts $i.to_s
		$i += 1
	end


	puts "begin-while:"
	begin
		puts $i.to_s
		$i += 1
	end while $i < 10

	puts "until:"
	until $i == 15
		puts $i.to_s
		$i +=1
	end

	puts "begin-until"
	begin
		puts $i.to_s
		$i += 1
	end until $i == 20

	puts "for:"
	for i in 20..24
		puts i.to_s
		i += 1
	end

	puts "each:"
	(25..29).each do |i|
		puts i.to_s
	end
end

# 3.
def mean_sigma(v)
	mean = 0
	sd = 0

	v.each do | element |
		mean += element
	end

	mean = mean/v.length
	
	v.each do | element |
		sd += (element - mean)**2
	end

	sd = Math.sqrt(sd/v.length)

	return mean,sd
end

def mean_sigma_demo
	numArray = Array.new(10) { |e| e = 2**e}

	puts "array:"
	puts numArray
	mean, sd = mean_sigma(numArray)
	puts "mean: #{mean} standard deviation: #{sd}"
end

# 4.
def sort(v)
	array = v
	loop do
		swapped = false

		(array.length-1).times do |i|
			if array[i] > array[i+1]
				array[i], array[i+1] = array[i+1], array[i]
				swapped = true
			end
		end

		break if not swapped
	end

	array
end

def sort_demo
	numArray = Array.new(10)
	(0..9).each do |i|
		numArray[i] = rand(100)
	end
	puts "array:"
	puts numArray
	puts "sorted:"
	puts sort(numArray)
	puts "old array: "
	puts numArray
end

# 5.
class Triangle
	@s1 = 0
	@s2 = 0
	@s3 = 0

	def initialize(side1,side2,side3)
		@s1 = side1
		@s2 = side2
		@s3 = side3
	end

	def s1=(s)
		@s1 = s
	end

	def s2=(s)
		@s2 = s
	end

	def s3=(s)
		@s3 = s
	end

	def s1
		@s1
	end

	def s2
		@s2
	end

	def s3
		@s3
	end

	def perimeter
		@s1 + @s2 + @s3
	end

	def area
		p = perimeter/2
		Math.sqrt(p*(p-@s1)*(p-@s2)*(p-@s3))
	end

	def test
		if @s1 >= @s2 + @s3 || @s2 >= @s1 + @s3 || @s3 >= @s1 + @s2
			return "triangle does not exist"
		end

		case 
		when @s1 == @s2 && @s2 == @s3
			type = "equilateral"
		when (@s1 == @s2 && @s1 != @s3) || (@s1 == @s3 && @s1 != @s2) || (@s3 == @s2 && @s3 != @s1)
			type = "isosceles"
		else
			type = "scalene"
		end

		if (@s1**2 + @s2**2 == @s3**2) || (@s1**2 + @s3**2 == @s2**2) || (@s2**2 + @s3**2 == @s1**2)
			return "right-#{type}"
		else
			return type
		end
	end
end

def displayTri(t)
	puts "Triangle: #{t.s1}, #{t.s2}, #{t.s3}"
	puts "Type: #{t.test}"
	if t.test != "triangle does not exist"
		puts "Perimeter: #{t.perimeter}"
		puts "Area: #{t.area}"
	end
end

def triangle_demo
	displayTri(Triangle.new(3,4,5))
	displayTri(Triangle.new(6,6,6))
	displayTri(Triangle.new(rand(10),rand(10),rand(10)))
	displayTri(Triangle.new(rand(10),rand(10),rand(10)))
	displayTri(Triangle.new(rand(10),rand(10),rand(10)))
end

# 4.
class Array
	def limited?(amin,amax)
		self.each do |i|
			if self[i] < amin || self[i] > amax
				return false
			end
		end
		true
	end

	def sorted?
		if self.first <= self.last
			for i in (0...self.length-1)
				if self[i] > self[i+1]
					return 0
				end
			end
			return 1
		else
			for i in (0...self.length-1)
				if self[i] < self[i+1]
					return 0
				end
			end
			return -1
		end
	end
end

def reverse(a)
	rev = []
	for i in (0...a.length)
		rev << a[-1 - i]
	end
	rev
end

def array_demo
	numArray = Array.new(10)
	(0...10).each do |i|
		numArray[i] = rand(10)
	end

	puts "array:"
	puts numArray
	puts "limited from 0-10:"
	if numArray.limited?(0,10)
		puts "true"
	else
		puts "false"
	end
	puts "limited from 4-6:"
	if numArray.limited?(4,6)
		puts "true"
	else
		puts "false"
	end
	puts "array.sorted?: #{numArray.sorted?}"
	puts "sorted array:"
	puts sort(numArray)
	puts "array.sorted?: #{numArray.sorted?}"
	puts "reverse-sorted array:"
	puts reverse(sort(numArray))
	puts "array.sorted?: #{reverse(sort(numArray)).sorted?}"
end


conditional_demo
$i = 0
loop_iterator_demo
mean_sigma_demo
sort_demo
triangle_demo
array_demo
