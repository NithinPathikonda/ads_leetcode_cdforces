// Exhaustive MNC Problem Archetypes Dataset
const initialProblems = [
  {
    id: 1,
    title: "LC 1: Two Sum",
    difficulty: "Easy",
    companies: ["Google", "Meta", "Amazon", "Apple"],
    pattern: "Hash Map / Complement",
    topic: "Arrays & Hashing",
    constraints: "N = 10^5, nums[i] = -10^9 to 10^9, target = -10^9 to 10^9",
    teaser: "Find two distinct indices in an unsorted array that add up to target.",
    intuition: "Store seen numbers in an unordered_map {value -> index}. For each element x, check if (target - x) was already seen in O(1) time using iterator.",
    timeComplexity: "O(N)",
    spaceComplexity: "O(N)",
    pitfall: "Cannot use the same element twice (e.g., [3, 3] with target 6). Check map BEFORE inserting current element. Use iterator to avoid double hashing.",
    code: `unordered_map<int, int> mpp;
for (int i = 0; i < nums.size(); ++i) {
    int comp = target - nums[i];
    auto it = mpp.find(comp);
    if (it != mpp.end()) return {it->second, i};
    mpp[nums[i]] = i;
}
return {};`,
    confidence: "mastered",
    nextReviewDays: 10
  },
  {
    id: 121,
    title: "LC 121: Best Time to Buy and Sell Stock",
    difficulty: "Easy",
    companies: ["Google", "Meta", "Amazon", "Microsoft", "Apple"],
    pattern: "Running Minimum / Kadane's",
    topic: "Arrays & Hashing",
    constraints: "N = 10^5, prices[i] = 0 to 10^4",
    teaser: "Maximize profit by choosing a single day to buy and a future day to sell.",
    intuition: "Maintain the minimum buying price seen so far (minPrice). At each day i, calculate current profit = prices[i] - minPrice, and update maxProfit.",
    timeComplexity: "O(N)",
    spaceComplexity: "O(1)",
    pitfall: "You cannot sell before you buy! Must process strictly left-to-right maintaining past minimum.",
    code: `int minPrice = INT_MAX, maxProfit = 0;
for (int price : prices) {
    minPrice = min(minPrice, price);
    maxProfit = max(maxProfit, price - minPrice);
}
return maxProfit;`,
    confidence: "again",
    nextReviewDays: 0
  },
  {
    id: 15,
    title: "LC 15: 3Sum",
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
    confidence: "again",
    nextReviewDays: 0
  },
  {
    id: 3,
    title: "LC 3: Longest Substring Without Repeating Characters",
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
    confidence: "again",
    nextReviewDays: 0
  },
  {
    id: 42,
    title: "LC 42: Trapping Rain Water",
    difficulty: "Hard",
    companies: ["Google", "Amazon", "Meta", "Goldman Sachs"],
    pattern: "Two Pointers / Invariant Boundaries",
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
    confidence: "again",
    nextReviewDays: 0
  },
  {
    id: 739,
    title: "LC 739: Daily Temperatures",
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
    confidence: "again",
    nextReviewDays: 0
  },
  {
    id: 875,
    title: "LC 875: Koko Eating Bananas",
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
    confidence: "again",
    nextReviewDays: 0
  },
  {
    id: 200,
    title: "LC 200: Number of Islands",
    difficulty: "Medium",
    companies: ["Amazon", "Google", "Microsoft", "Bloomberg"],
    pattern: "Graph DFS / BFS / Flood Fill",
    topic: "Graphs",
    constraints: "m, n <= 300, grid[i][j] is '0' or '1'",
    teaser: "Count the number of connected components of '1's (land) surrounded by '0's (water).",
    intuition: "Iterate over all cells. When grid[r][c] == '1', increment island count and trigger DFS/BFS to sink the entire island (flip '1' to '0' in-place).",
    timeComplexity: "O(M * N)",
    spaceComplexity: "O(M * N) recursion stack worst-case",
    pitfall: "Check grid boundaries (r >= 0 && r < m && c >= 0 && c < n) BEFORE accessing grid[r][c]. Sink visited land to avoid infinite loop.",
    code: `void dfs(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1') return;
    grid[r][c] = '0'; // Sink island
    dfs(grid, r+1, c); dfs(grid, r-1, c);
    dfs(grid, r, c+1); dfs(grid, r, c-1);
}`,
    confidence: "again",
    nextReviewDays: 0
  },
  {
    id: 207,
    title: "LC 207: Course Schedule",
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
    confidence: "again",
    nextReviewDays: 0
  },
  {
    id: 322,
    title: "LC 322: Coin Change",
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
    confidence: "again",
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

// Load from LocalStorage or initialize with merge
function initData() {
  const saved = localStorage.getItem('nithin_dsa_problems');
  if (saved) {
    try {
      const parsed = JSON.parse(saved);
      const stateMap = new Map(parsed.map(p => [p.id, p]));
      problems = initialProblems.map(p => {
        if (stateMap.has(p.id)) {
          const s = stateMap.get(p.id);
          return { ...p, confidence: s.confidence || p.confidence, nextReviewDays: s.nextReviewDays ?? p.nextReviewDays };
        }
        return p;
      });
    } catch (e) {
      problems = initialProblems;
    }
  } else {
    problems = initialProblems;
  }
  saveData();
}

function saveData() {
  localStorage.setItem('nithin_dsa_problems', JSON.stringify(problems));
}

// Reset all filters to show everything
function resetAllFilters() {
  currentFilter = 'all';
  currentCategory = 'all';
  searchQuery = '';
  searchInput.value = '';

  document.querySelectorAll('.filter-btn').forEach(b => b.classList.remove('active'));
  const allFilterBtn = document.querySelector('.filter-btn[data-filter="all"]');
  if (allFilterBtn) allFilterBtn.classList.add('active');

  document.querySelectorAll('.tag-chip').forEach(c => c.classList.remove('active'));
  const allTagChip = document.querySelector('.tag-chip[data-topic="all"]');
  if (allTagChip) allTagChip.classList.add('active');

  currentIndex = 0;
  renderActiveCard();
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
const badgeRow = document.getElementById('badgeRow');
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

  // Unflip first if flipped
  if (isFlipped) {
    flipper.classList.remove('flipped');
    isFlipped = false;
  }

  if (filtered.length === 0) {
    // Empty state handling
    badgeRow.style.display = 'none';
    cardCounter.innerText = "0 / 0";
    problemTitle.innerHTML = `<span style="color: var(--accent-amber);">No problems match this combination</span>`;
    problemTeaser.innerHTML = `
      <div style="margin-top: 10px; display: flex; flex-direction: column; align-items: center; gap: 14px;">
        <span style="color: var(--text-muted); font-size: 14px;">
          Filter: <strong>${currentFilter.toUpperCase()}</strong> | Topic: <strong>${currentCategory}</strong>
        </span>
        <button id="emptyResetBtn" style="background: linear-gradient(135deg, var(--accent-cyan), var(--accent-indigo)); color: white; border: none; padding: 10px 22px; border-radius: var(--radius-full); font-weight: 700; cursor: pointer; box-shadow: 0 4px 15px rgba(56, 189, 248, 0.4); font-size: 13px;">
          ⚡ Reset Filters & Show All
        </button>
      </div>
    `;
    constraintsText.innerText = "";
    prevBtn.disabled = true;
    nextBtn.disabled = true;

    const btn = document.getElementById('emptyResetBtn');
    if (btn) btn.addEventListener('click', resetAllFilters);

    updateStats();
    renderGrid();
    return;
  }

  // Restore badge visibility
  badgeRow.style.display = 'flex';

  if (currentIndex >= filtered.length) currentIndex = 0;
  if (currentIndex < 0) currentIndex = filtered.length - 1;

  const p = filtered[currentIndex];

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
  const filtered = getFilteredProblems();
  if (filtered.length === 0) return;
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

// Live Local C++ Test Runner Listener
const runCppBtn = document.getElementById('runCppBtn');
const runStatus = document.getElementById('runStatus');
const runOutput = document.getElementById('runOutput');

if (runCppBtn) {
  runCppBtn.addEventListener('click', async (e) => {
    e.stopPropagation();
    const filtered = getFilteredProblems();
    if (filtered.length === 0) return;
    const current = filtered[currentIndex];
    
    // Map default filepaths if missing
    let targetPath = current.filepath;
    if (!targetPath) {
      if (current.id === 1) targetPath = "01_arrays_hashing/lc_0001_two_sum.cpp";
      else if (current.id === 121) targetPath = "01_arrays_hashing/lc_0121_best_time_to_buy_and_sell_stock.cpp";
      else {
        runStatus.innerText = "File not created yet";
        runStatus.style.color = "var(--accent-amber)";
        runOutput.style.display = "block";
        runOutput.innerText = "This problem starter file is coming up next!";
        return;
      }
    }

    runStatus.innerText = "Compiling & executing...";
    runStatus.style.color = "var(--accent-amber)";
    runOutput.style.display = "block";
    runOutput.innerText = `Running clang++ -std=c++20 ${targetPath}...`;

    try {
      const res = await fetch('/api/run-code', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ filepath: targetPath })
      });
      if (!res.ok) throw new Error("API call failed");
      const data = await res.json();
      if (data.success) {
        runStatus.innerText = "PASSED (Exit 0)";
        runStatus.style.color = "var(--accent-emerald)";
      } else {
        runStatus.innerText = "FAILED in " + data.stage;
        runStatus.style.color = "var(--accent-rose)";
      }
      runOutput.innerText = data.output || "No output returned.";
    } catch (err) {
      runStatus.innerText = "Server not running";
      runStatus.style.color = "var(--accent-rose)";
      runOutput.innerText = "Start the FastAPI backend with: ./venv_ads/bin/python server.py\nThen click Run again!";
    }
  });
}

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

