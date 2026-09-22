// Initial High-Yield MNC Problem Flashcards Dataset
const initialProblems = [
  {
    id: 1,
    title: "Two Sum",
    difficulty: "Easy",
    companies: ["Google", "Meta", "Amazon", "Apple"],
    pattern: "Hash Map / Complement",
    topic: "Arrays & Hashing",
    constraints: "N = 10^5, nums[i] = -10^9 to 10^9, target = -10^9 to 10^9",
    teaser: "Find two distinct indices in an unsorted array that add up to target.",
    intuition: "Store seen numbers in an unordered_map {value -> index}. For each element x, check if (target - x) was already seen in O(1) time.",
    timeComplexity: "O(N)",
    spaceComplexity: "O(N)",
    pitfall: "Cannot use the same element twice (e.g., [3, 3] with target 6). Check map BEFORE inserting current element.",
    code: `unordered_map<int, int> seen;
for (int i = 0; i < nums.size(); ++i) {
    int comp = target - nums[i];
    if (seen.count(comp)) return {seen[comp], i};
    seen[nums[i]] = i;
}
return {};`,
    confidence: "new",
    nextReviewDays: 0
  },
  {
    id: 2,
    title: "3Sum",
    difficulty: "Medium",
    companies: ["Meta", "Amazon", "Google", "Microsoft"],
    pattern: "Two Pointers (Sort First)",
    topic: "Two Pointers",
    constraints: "N = 3000, nums[i] = -10^5 to 10^5",
    teaser: "Find all unique triplets [nums[i], nums[j], nums[k]] that sum to 0.",
    intuition: "Sort array in O(N log N). Fix nums[i] with an outer loop. Run two pointers (left = i+1, right = n-1) to find pairs summing to -nums[i].",
    timeComplexity: "O(N^2)",
    spaceComplexity: "O(1) auxiliary",
    pitfall: "Duplicate triplets! Skip duplicate nums[i] in the outer loop, and skip duplicates of left and right pointers after finding a valid match.",
    code: `sort(nums.begin(), nums.end());
for (int i = 0; i < n - 2; ++i) {
    if (i > 0 && nums[i] == nums[i-1]) continue;
    int l = i + 1, r = n - 1;
    while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
            res.push_back({nums[i], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l+1]) l++;
            while (l < r && nums[r] == nums[r-1]) r--;
            l++; r--;
        } else if (sum < 0) l++;
        else r--;
    }
}`,
    confidence: "new",
    nextReviewDays: 0
  },
  {
    id: 3,
    title: "Longest Substring Without Repeating Characters",
    difficulty: "Medium",
    companies: ["Amazon", "Google", "Meta", "Bloomberg"],
    pattern: "Dynamic Sliding Window",
    topic: "Two Pointers",
    constraints: "s.length <= 5 * 10^4",
    teaser: "Find the length of the longest contiguous substring without duplicate characters.",
    intuition: "Expand right pointer and track character last-seen index. When a duplicate appears at right, jump left pointer to max(left, lastSeen[char] + 1).",
    timeComplexity: "O(N)",
    spaceComplexity: "O(min(N, M)) - character map",
    pitfall: "Left pointer must ONLY move forward! Use left = max(left, lastSeen[s[r]] + 1) to avoid moving left backward on stale indices.",
    code: `vector<int> last(256, -1);
int maxLen = 0, l = 0;
for (int r = 0; r < s.size(); ++r) {
    if (last[s[r]] >= l) l = last[s[r]] + 1;
    last[s[r]] = r;
    maxLen = max(maxLen, r - l + 1);
}`,
    confidence: "new",
    nextReviewDays: 0
  },
  {
    id: 4,
    title: "Trapping Rain Water",
    difficulty: "Hard",
    companies: ["Google", "Amazon", "Meta", "Goldman Sachs"],
    pattern: "Two Pointers or Monotonic Stack",
    topic: "Two Pointers",
    constraints: "N = 2 * 10^4, height[i] >= 0",
    teaser: "Calculate how much water an elevation map can trap after raining.",
    intuition: "Water above index i is min(maxLeft, maxRight) - height[i]. Using two pointers (l=0, r=n-1), move the pointer with the smaller max boundary inward.",
    timeComplexity: "O(N)",
    spaceComplexity: "O(1) auxiliary",
    pitfall: "Only update water trapped by the lower boundary pointer because the opposite boundary is guaranteed to be taller or equal.",
    code: `int l = 0, r = n - 1, maxL = 0, maxR = 0, water = 0;
while (l < r) {
    if (height[l] <= height[r]) {
        if (height[l] >= maxL) maxL = height[l];
        else water += maxL - height[l];
        l++;
    } else {
        if (height[r] >= maxR) maxR = height[r];
        else water += maxR - height[r];
        r--;
    }
}`,
    confidence: "new",
    nextReviewDays: 0
  },
  {
    id: 5,
    title: "Daily Temperatures (Next Greater Element)",
    difficulty: "Medium",
    companies: ["Meta", "Amazon", "Google"],
    pattern: "Monotonic Decreasing Stack",
    topic: "Stack & Monotonic Stack",
    constraints: "N = 10^5, temperatures[i] = 30 to 100",
    teaser: "Return an array where answer[i] is the number of days until a warmer temperature.",
    intuition: "Maintain a stack of INDICES with strictly decreasing temperatures. When a warmer day arrives, pop indices and resolve their answers (curr - popped).",
    timeComplexity: "O(N) - each element pushed & popped at most once",
    spaceComplexity: "O(N)",
    pitfall: "Always store INDICES in monotonic stack, not values, so you can compute distances!",
    code: `stack<int> st; // stores indices
vector<int> res(n, 0);
for (int i = 0; i < n; ++i) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        int prev = st.top(); st.pop();
        res[prev] = i - prev;
    }
    st.push(i);
}`,
    confidence: "new",
    nextReviewDays: 0
  },
  {
    id: 6,
    title: "Koko Eating Bananas",
    difficulty: "Medium",
    companies: ["Google", "Uber", "Amazon", "Airbnb"],
    pattern: "Binary Search on Answer (Predicate)",
    topic: "Binary Search",
    constraints: "piles.length <= 10^4, h <= 10^9, piles[i] <= 10^9",
    teaser: "Find minimum integer speed K to eat all bananas within H hours.",
    intuition: "Monotonic property: If speed K is fast enough, any speed > K is also valid. Binary search K in range [1, max(piles)].",
    timeComplexity: "O(N log(max(pile)))",
    spaceComplexity: "O(1)",
    pitfall: "Integer overflow in total hours! Use long long for hour sum: (pile + k - 1) / k.",
    code: `auto canEat = [&](long long k) {
    long long hours = 0;
    for (int p : piles) hours += (p + k - 1) / k;
    return hours <= h;
};
long long low = 1, high = *max_element(piles.begin(), piles.end()), ans = high;
while (low <= high) {
    long long mid = low + (high - low) / 2;
    if (canEat(mid)) { ans = mid; high = mid - 1; }
    else low = mid + 1;
}`,
    confidence: "new",
    nextReviewDays: 0
  },
  {
    id: 7,
    title: "Course Schedule (Cycle in Directed Graph)",
    difficulty: "Medium",
    companies: ["Google", "Amazon", "Microsoft", "Uber"],
    pattern: "Topological Sort / Kahn's Algorithm",
    topic: "Graphs",
    constraints: "numCourses <= 2000, prerequisites.length <= 5000",
    teaser: "Determine if it is possible to finish all courses given prerequisite pairs.",
    intuition: "Model as directed graph. Compute in-degrees of all nodes. Push nodes with in-degree 0 to queue. Decrement neighbors' in-degree. If count processed == numCourses, no cycle.",
    timeComplexity: "O(V + E)",
    spaceComplexity: "O(V + E)",
    pitfall: "Cycles in directed graph cannot be topologically sorted. If visitedCount < numCourses, a cycle exists!",
    code: `vector<vector<int>> adj(n);
vector<int> inDegree(n, 0);
for (auto& p : prerequisites) {
    adj[p[1]].push_back(p[0]);
    inDegree[p[0]]++;
}
queue<int> q;
for (int i = 0; i < n; ++i) if (inDegree[i] == 0) q.push(i);
int count = 0;
while (!q.empty()) {
    int u = q.front(); q.pop(); count++;
    for (int v : adj[u]) if (--inDegree[v] == 0) q.push(v);
}
return count == n;`,
    confidence: "new",
    nextReviewDays: 0
  },
  {
    id: 8,
    title: "Coin Change (Min Coins for Amount)",
    difficulty: "Medium",
    companies: ["Amazon", "Bloomberg", "Google", "Apple"],
    pattern: "Unbounded Knapsack DP (1D)",
    topic: "Dynamic Programming",
    constraints: "coins.length <= 12, amount <= 10^4",
    teaser: "Find the fewest number of coins that make up the target amount.",
    intuition: "dp[a] = min coins to form amount a. Base case: dp[0] = 0. Transition: dp[a] = min(dp[a], dp[a - coin] + 1) for all coins <= a.",
    timeComplexity: "O(amount * number of coins)",
    spaceComplexity: "O(amount)",
    pitfall: "Initialize array with amount + 1 (representing infinity) to avoid 32-bit INT_MAX overflow when adding 1.",
    code: `vector<int> dp(amount + 1, amount + 1);
dp[0] = 0;
for (int a = 1; a <= amount; ++a) {
    for (int c : coins) {
        if (a - c >= 0) {
            dp[a] = min(dp[a], dp[a - c] + 1);
        }
    }
}
return dp[amount] > amount ? -1 : dp[amount];`,
    confidence: "new",
    nextReviewDays: 0
  }
];

// App State
let problems = [];
let currentIndex = 0;
let isFlipped = false;
let currentFilter = 'all';
let currentCategory = 'all';
let searchQuery = '';

// Load from LocalStorage or initialize
function initData() {
  const saved = localStorage.getItem('nithin_dsa_problems');
  if (saved) {
    try {
      problems = JSON.parse(saved);
    } catch (e) {
      problems = initialProblems;
    }
  } else {
    problems = initialProblems;
    saveData();
  }
}

function saveData() {
  localStorage.setItem('nithin_dsa_problems', JSON.stringify(problems));
}

// Get filtered problem list
function getFilteredProblems() {
  return problems.filter(p => {
    // Top filter tab
    if (currentFilter === 'due' && p.confidence === 'mastered') return false;
    if (currentFilter === 'google' && !p.companies.includes('Google')) return false;
    if (currentFilter === 'meta' && !p.companies.includes('Meta')) return false;
    if (currentFilter === 'again' && p.confidence !== 'again') return false;
    if (currentFilter === 'mastered' && p.confidence !== 'mastered') return false;

    // Category filter
    if (currentCategory !== 'all' && p.topic !== currentCategory) return false;

    // Search query
    if (searchQuery.trim() !== '') {
      const q = searchQuery.toLowerCase();
      const matchTitle = p.title.toLowerCase().includes(q);
      const matchPattern = p.pattern.toLowerCase().includes(q);
      const matchCompany = p.companies.some(c => c.toLowerCase().includes(q));
      if (!matchTitle && !matchPattern && !matchCompany) return false;
    }

    return true;
  });
}

// DOM Elements
const flipper = document.getElementById('flashcardFlipper');
const cardCounter = document.getElementById('cardCounter');
const badgeDifficulty = document.getElementById('badgeDifficulty');
const badgePattern = document.getElementById('badgePattern');
const badgeCompanies = document.getElementById('badgeCompanies');
const problemTitle = document.getElementById('problemTitle');
const problemTeaser = document.getElementById('problemTeaser');
const constraintsText = document.getElementById('constraintsText');

const backPatternTitle = document.getElementById('backPatternTitle');
const backTimeComp = document.getElementById('backTimeComp');
const backSpaceComp = document.getElementById('backSpaceComp');
const backIntuition = document.getElementById('backIntuition');
const backCode = document.getElementById('backCode');
const backPitfall = document.getElementById('backPitfall');

const prevBtn = document.getElementById('prevBtn');
const nextBtn = document.getElementById('nextBtn');
const searchInput = document.getElementById('searchInput');
const problemsGrid = document.getElementById('problemsGrid');

// Stats counters
const statMastered = document.getElementById('statMastered');
const statLearning = document.getElementById('statLearning');
const statDue = document.getElementById('statDue');

// Render active card
function renderActiveCard() {
  const filtered = getFilteredProblems();
  if (filtered.length === 0) {
    problemTitle.innerText = "No problems match your filter";
    problemTeaser.innerText = "Try resetting filters or search query.";
    constraintsText.innerText = "";
    cardCounter.innerText = "0 / 0";
    prevBtn.disabled = true;
    nextBtn.disabled = true;
    return;
  }

  if (currentIndex >= filtered.length) currentIndex = 0;
  if (currentIndex < 0) currentIndex = filtered.length - 1;

  const p = filtered[currentIndex];

  // Unflip first if flipped
  if (isFlipped) {
    flipper.classList.remove('flipped');
    isFlipped = false;
  }

  // Front Face
  cardCounter.innerText = `${currentIndex + 1} / ${filtered.length}`;
  problemTitle.innerText = p.title;
  problemTeaser.innerText = p.teaser;
  constraintsText.innerText = `Constraints: ${p.constraints}`;

  // Difficulty badge
  badgeDifficulty.className = 'badge';
  if (p.difficulty === 'Easy') badgeDifficulty.classList.add('badge-easy');
  else if (p.difficulty === 'Medium') badgeDifficulty.classList.add('badge-medium');
  else badgeDifficulty.classList.add('badge-hard');
  badgeDifficulty.innerText = p.difficulty;

  badgePattern.innerText = p.pattern;
  badgeCompanies.innerText = p.companies.join(', ');

  // Back Face
  backPatternTitle.innerText = p.pattern;
  backTimeComp.innerText = p.timeComplexity;
  backSpaceComp.innerText = p.spaceComplexity;
  backIntuition.innerText = p.intuition;
  backCode.innerText = p.code;
  backPitfall.innerText = p.pitfall;

  prevBtn.disabled = filtered.length <= 1;
  nextBtn.disabled = filtered.length <= 1;

  updateStats();
  renderGrid();
}

function updateStats() {
  const mastered = problems.filter(p => p.confidence === 'mastered').length;
  const learning = problems.filter(p => p.confidence === 'hard' || p.confidence === 'again').length;
  const due = problems.filter(p => p.confidence !== 'mastered').length;

  statMastered.innerText = mastered;
  statLearning.innerText = learning;
  statDue.innerText = due;
}

// Flip Card
function flipCard() {
  isFlipped = !isFlipped;
  if (isFlipped) flipper.classList.add('flipped');
  else flipper.classList.remove('flipped');
}

// Navigation
function nextCard() {
  const filtered = getFilteredProblems();
  if (filtered.length <= 1) return;
  currentIndex = (currentIndex + 1) % filtered.length;
  renderActiveCard();
}

function prevCard() {
  const filtered = getFilteredProblems();
  if (filtered.length <= 1) return;
  currentIndex = (currentIndex - 1 + filtered.length) % filtered.length;
  renderActiveCard();
}

// Spaced Repetition Rate Card
function rateCard(confidenceLevel) {
  const filtered = getFilteredProblems();
  if (filtered.length === 0) return;

  const currentProblem = filtered[currentIndex];
  const originalIndex = problems.findIndex(p => p.id === currentProblem.id);
  if (originalIndex !== -1) {
    problems[originalIndex].confidence = confidenceLevel;
    if (confidenceLevel === 'again') {
      problems[originalIndex].nextReviewDays = 0; // Due today
    } else if (confidenceLevel === 'hard') {
      problems[originalIndex].nextReviewDays = 3; // R1 (+3 days)
    } else if (confidenceLevel === 'mastered') {
      problems[originalIndex].nextReviewDays = 10; // R2 (+10 days)
    }
    saveData();
  }

  // Micro vibration / visual transition then move to next
  nextCard();
}

// Render Grid of All Problems
function renderGrid() {
  const filtered = getFilteredProblems();
  problemsGrid.innerHTML = '';

  filtered.forEach((p, idx) => {
    const mini = document.createElement('div');
    mini.className = 'mini-card';
    if (idx === currentIndex) mini.style.borderColor = 'var(--accent-cyan)';

    mini.innerHTML = `
      <div class="mini-card-meta">
        <span class="badge ${p.difficulty === 'Easy' ? 'badge-easy' : p.difficulty === 'Medium' ? 'badge-medium' : 'badge-hard'}">${p.difficulty}</span>
        <span style="color: var(--text-dim); font-size: 11px;">${p.topic}</span>
      </div>
      <div class="mini-card-title">${p.title}</div>
      <div style="font-size: 12px; color: var(--accent-cyan); font-weight: 500;">${p.pattern}</div>
      <div style="font-size: 11px; color: var(--text-muted); display: flex; justify-content: space-between; margin-top: 4px;">
        <span>${p.companies.slice(0, 2).join(', ')}</span>
        <span style="font-weight: 700; color: ${p.confidence === 'mastered' ? 'var(--accent-emerald)' : p.confidence === 'hard' ? 'var(--accent-amber)' : 'var(--accent-rose)'};">
          ${p.confidence.toUpperCase()}
        </span>
      </div>
    `;

    mini.addEventListener('click', () => {
      currentIndex = idx;
      renderActiveCard();
      window.scrollTo({ top: 120, behavior: 'smooth' });
    });

    problemsGrid.appendChild(mini);
  });
}

// Event Listeners
flipper.addEventListener('click', flipCard);
prevBtn.addEventListener('click', (e) => { e.stopPropagation(); prevCard(); });
nextBtn.addEventListener('click', (e) => { e.stopPropagation(); nextCard(); });

document.getElementById('rateAgain').addEventListener('click', () => rateCard('again'));
document.getElementById('rateHard').addEventListener('click', () => rateCard('hard'));
document.getElementById('rateGood').addEventListener('click', () => rateCard('mastered'));

// Filter tab buttons
document.querySelectorAll('.filter-btn').forEach(btn => {
  btn.addEventListener('click', (e) => {
    document.querySelectorAll('.filter-btn').forEach(b => b.classList.remove('active'));
    e.target.classList.add('active');
    currentFilter = e.target.dataset.filter;
    currentIndex = 0;
    renderActiveCard();
  });
});

// Category Chips
document.querySelectorAll('.tag-chip').forEach(chip => {
  chip.addEventListener('click', (e) => {
    document.querySelectorAll('.tag-chip').forEach(c => c.classList.remove('active'));
    e.target.classList.add('active');
    currentCategory = e.target.dataset.topic;
    currentIndex = 0;
    renderActiveCard();
  });
});

// Search input
searchInput.addEventListener('input', (e) => {
  searchQuery = e.target.value;
  currentIndex = 0;
  renderActiveCard();
});

// Keyboard Navigation
window.addEventListener('keydown', (e) => {
  if (document.activeElement === searchInput) return;

  if (e.code === 'Space') {
    e.preventDefault();
    flipCard();
  } else if (e.code === 'ArrowRight') {
    e.preventDefault();
    nextCard();
  } else if (e.code === 'ArrowLeft') {
    e.preventDefault();
    prevCard();
  } else if (e.key === '1') {
    rateCard('again');
  } else if (e.key === '2') {
    rateCard('hard');
  } else if (e.key === '3') {
    rateCard('mastered');
  }
});

// Boot app
initData();
renderActiveCard();
